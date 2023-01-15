package main

import (
	"fmt"
	"html"
	"net/http"
	"rest/romanNumerals"
	"strconv"
	"strings"
	"time"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		urlPathElements := strings.Split(r.URL.Path, "/")
		if urlPathElements[1] == "roman_number" {
			number, _ := stringconv.Atoi(strings.TrimSpace(urlPathElements[2]))
			if number == 0 || number > 10 {
				w.WriteHeader(http.StatusNotFound)
				return
			}
			fmt.Fprintf(w, "%q", html.EscapeString(romanNumerals.Numerals[number]))
			return
		}
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("400 - Bad request"))
	})

	s := http.Server{
		Addr:           ":8000",
		ReadTimeout:    10 * time.Second,
		WriteTimeout:   10 * time.Second,
		MaxHeaderBytes: 1 << 20,
	}

	s.ListenAndServe()
}
