package article

import (
	"fmt"
	mux "github.com/gorilla/mux"
	"net/http"
)

func ArtichleHandler(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	w.WriteHeader(http.StatusOK)

	fmt.Fprintf(w, "{%q:%v}", "id", vars["id"])
}

func Routes(R *mux.Router) {
	R.StrictSlash(true)
	s := R.PathPrefix("/articles").Subrouter()
	s.HandleFunc("/{id:[0-9]+}", ArtichleHandler).Name("articleRoute")
	R.PathPrefix("/static/").Handler(http.StripPrefix("/static/", http.FileServer(http.Dir("./static"))))
}
