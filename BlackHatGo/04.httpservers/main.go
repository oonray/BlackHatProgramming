package main

import "net/http"
import "context"
import "fmt"
import "github.com/gorilla/mux"
import "github.com/urfave/negroni"

type badAuth struct {
	Username string
	Password string
}
  
func (b *badAuth) ServeHTTP(w http.ResponseWriter, r *http.Request, next http.HandlerFunc){
	username := r.URL.Query().Get("username")
	password := r.URL.Query().Get("password")

	if username != b.Username || password != b.Password {
		http.Error(w,"Unauthorized",401)
		return
	}
	
	ctx := context.WithValue(r.Context(),"username",username)
	r = r.WithContext(ctx)
	next(w,r)
}

func hello(w http.ResponseWriter, r *http.Request){
	username := r.Context().Value("username")
	fmt.Fprintf(w,"Hi %s\n",username)
}

func main(){
	r := mux.NewRouter()
	n := negroni.Classic()

    r.HandleFunc("/hello",hello).Methods("GET")

	n.Use(&badAuth{
		Username: "admin",
		Password: "password",
	})

	n.UseHandler(r)
	http.ListenAndServe("192.168.10.127:8085",n)
}
