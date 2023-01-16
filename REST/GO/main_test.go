package main

import (
	log "github.com/sirupsen/logrus"
	"testing"
)

func TestArticle(t *testing.T) {
	Routes()

	url, err := R.Get("articleRoute").URL("category", "books", "id", "123")

	if err != nil {
		t.Error(err)
	}

	log.Printf("%s", url)

}
