package main

import (
	"log"
	"net/http"
	"net/http/cookiejar"
	"net/http/httptest"
	"testing"

	mux "github.com/gorilla/mux"
)

var router *mux.Router
var server *httptest.Server
var client http.Client

func init() {
	r := mux.NewRouter()
	r.HandleFunc("/getToken", getTokenHandler)
	r.HandleFunc("/healthcheck", HealthcheckHandler)

	server = httptest.NewServer(r)

	jar, err := cookiejar.New(nil)
	if err != nil {
		log.Fatal(err)
		return
	}

	client = http.Client{Jar: jar}
}

func TestHelthHandlerInit(t *testing.T) {
	res, err := client.Get(server.URL + "/healthcheck")
	if err != nil {
		t.Errorf("Could not make response | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode != http.StatusForbidden {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}
}
