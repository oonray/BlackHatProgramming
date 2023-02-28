package main

import (
	"encoding/json"
	"log"
	"net/http"
	"net/http/cookiejar"
	"net/http/httptest"
	"testing"

	mux "github.com/gorilla/mux"
)

var (
	router *mux.Router
	server *httptest.Server
	client http.Client
	resp   Response
)

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

	// Should get error
	if res.StatusCode != http.StatusForbidden {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}
}

func TestTokenHandlerInit(t *testing.T) {
	res, err := client.PostForm(server.URL+"/getToken", map[string][]string{
		"username": []string{"admin"},
		"password": []string{"password"},
	})

	if err != nil {
		t.Errorf("Could not make request | %s", err)
	}
	defer res.Body.Close()

	err = json.NewDecoder(res.Body).Decode(&resp)
	if err != nil {
		t.Errorf("Could not parse request | %s", err)
	}
}

func TestHelthHandler(t *testing.T) {
	req, err := http.NewRequest("GET", server.URL+"/healthcheck", nil)
	if err != nil {
		t.Errorf("Could not create request | %s", err)
	}

	req.Header.Set("access_token", resp.Token)

	res, err := client.Do(req)
	if err != nil {
		t.Errorf("Could not create request | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode == http.StatusForbidden {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}
}
