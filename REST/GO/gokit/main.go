package main

import (
	kitlog "github.com/go-kit/kit/log"
	httpt "github.com/go-kit/kit/transport/http"
	"log"
	"net/http"
	"os"
	hlp "rest/gokit/encryption/helpers"
)

func main() {
	logger := kitlog.NewLogfmtLogger(os.Stderr)

	var svc hlp.EncryptService
	svc = hlp.EncryptServiceInstance{}
	svc = hlp.LoggingMiddleware{Logger: logger, Next: svc}

	cryptHandler := httpt.NewServer(hlp.MakeEncryptEndpoint(svc), hlp.DecodeEncryptRequest, hlp.EncodeResponse)
	decryptHandler := httpt.NewServer(hlp.MakeDecryptEndpoint(svc), hlp.DecodeDecryptRequest, hlp.EncodeResponse)

	http.Handle("/encrypt", cryptHandler)
	http.Handle("/decrypt", decryptHandler)

	log.Fatal(http.ListenAndServe(":8080", nil))
}
