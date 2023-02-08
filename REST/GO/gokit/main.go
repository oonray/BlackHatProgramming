package main

import (
	httpt "github.com/go-kit/kit/transport/http"
	"log"
	"net/http"
	hlp "rest/gokit/encryption/helpers"
)

func main() {
	svc := hlp.EncryptServiceInstance{}
	cryptHandler := httpt.NewServer(hlp.MakeEncryptEndpoint(svc), hlp.DecodeEncryptRequest, hlp.EncodeResponse)
	decryptHandler := httpt.NewServer(hlp.MakeDecryptEndpoint(svc), hlp.DecodeDecryptRequest, hlp.EncodeResponse)

	http.Handle("/encrypt", cryptHandler)
	http.Handle("/decrypt", decryptHandler)

	log.Fatal(http.ListenAndServe(":8080", nil))
}
