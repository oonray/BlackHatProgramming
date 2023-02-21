package main

import (
	kitlog "github.com/go-kit/kit/log"
	promMet "github.com/go-kit/kit/metrics/prometheus"
	httpt "github.com/go-kit/kit/transport/http"
	prom "github.com/prometheus/client_golang/prometheus"
	httpProm "github.com/prometheus/client_golang/prometheus/promhttp"
	"log"
	"net/http"
	"os"
	hlp "rest/gokit/encryption/helpers"
)

func main() {
	logger := kitlog.NewLogfmtLogger(os.Stderr)
	fieldKeys := []string{"method", "error"}
	requestCount := promMet.NewCounterFrom(prom.CounterOpts{
		Namespace: "encryption",
		Subsystem: "my_service",
		Name:      "request_count",
		Help:      "Number of requests received",
	}, fieldKeys)

	requestLatency := promMet.NewSummaryFrom(prom.SummaryOpts{
		Namespace: "encryption",
		Subsystem: "my_service",
		Name:      "request_latency",
		Help:      "The latency of the request",
	}, fieldKeys)

	var svc hlp.EncryptService
	svc = hlp.EncryptServiceInstance{}
	svc = hlp.LoggingMiddleware{Logger: logger, Next: svc}
	svc = hlp.InstrumentationMiddleware{
		Next:     svc,
		RLatency: requestLatency,
		RCount:   requestCount,
	}

	cryptHandler := httpt.NewServer(hlp.MakeEncryptEndpoint(svc), hlp.DecodeEncryptRequest, hlp.EncodeResponse)
	decryptHandler := httpt.NewServer(hlp.MakeDecryptEndpoint(svc), hlp.DecodeDecryptRequest, hlp.EncodeResponse)

	http.Handle("/encrypt", cryptHandler)
	http.Handle("/decrypt", decryptHandler)
	http.Handle("/metrics", httpProm.Handler())
	log.Fatal(http.ListenAndServe("http://10.42.0.1:8080", nil))
}
