package main

import (
	"io/ioutil"
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
	router := mux.NewRouter()
	router.HandleFunc("/login", LoginHandler)
	router.HandleFunc("/healthcheck", HealthcheckHandler)
	router.HandleFunc("/logout", LogoutHandler)

	server = httptest.NewServer(router)

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

func TestLoginHandler(t *testing.T) {
	res, err := client.PostForm(server.URL+"/login", map[string][]string{"username": []string{"admin"}, "password": []string{"password"}})
	if err != nil {
		t.Errorf("Could not make response | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}

	_, err = ioutil.ReadAll(res.Body)
	if err != nil {
		t.Errorf("Could not read response | %s", err)
	}

	log.Printf("Cookies: %s", res.Cookies())
}

func TestHelthHandler(t *testing.T) {
	res, err := client.Get(server.URL + "/healthcheck")
	if err != nil {
		t.Errorf("Could not make response | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}

	data, err := ioutil.ReadAll(res.Body)
	if err != nil {
		t.Errorf("Could not read response | %s", err)
	}

	log.Printf("Check data: %s", data)
}

func TestILogoutHandler(t *testing.T) {
	res, err := client.Get(server.URL + "/logout")
	if err != nil {
		t.Errorf("Could not make response | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}
}

func TestHelthHandlerPost(t *testing.T) {
	res, err := client.Get(server.URL + "/healthcheck")
	if err != nil {
		t.Errorf("Could not make response | %s", err)
	}
	defer res.Body.Close()

	if res.StatusCode != http.StatusForbidden {
		t.Errorf("Wrong Status Code | status: %d", res.StatusCode)
	}
}
