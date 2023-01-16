package romanNumerals

import (
	"fmt"
	"html"
	"net/http"
	"strconv"
	"strings"
)

var (
	Numerals map[int]string = map[int]string{
		1:  "i",
		2:  "ii",
		3:  "iii",
		4:  "iv",
		5:  "v",
		6:  "vi",
		7:  "vii",
		8:  "viii",
		9:  "ix",
		10: "x",
	}
)

func RomanNumeralsHandler(w http.ResponseWriter, r *http.Request) {
	urlPathElements := strings.Split(r.URL.Path, "/")
	if urlPathElements[1] == "roman_number" {
		number, _ := strconv.Atoi(strings.TrimSpace(urlPathElements[2]))
		if number == 0 || number > 10 {
			w.WriteHeader(http.StatusNotFound)
			return
		}
		fmt.Fprintf(w, "%q", html.EscapeString(Numerals[number]))
		return
	}
	w.WriteHeader(http.StatusBadRequest)
	w.Write([]byte("400 - Bad request"))
}
