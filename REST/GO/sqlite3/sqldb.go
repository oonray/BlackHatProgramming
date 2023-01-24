package main

import (
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

type Book struct {
	Id     string `json:string,omitempty`
	Name   string `json:name,omitmepty`
	Author string `json:author, omitempty`
}

type SQLServer struct {
	Db *gorm.DB
}

func (s *SQLServer) GetBookId(id string) *[]Book {
	var book []Book
	s.Db.Find(&book, id)
	return &book
}

func (s *SQLServer) GetBookAuthor(author string) *[]Book {
	var book []Book
	s.Db.Find(&book, "Author=?", author)
	return &book
}

func (s *SQLServer) GetBooks(author string) *[]Book {
	var book []Book
	s.Db.Find(&book)
	return &book
}

func NewSQLServer(name string) (*SQLServer, error) {
	var err error = nil

	sql := new(SQLServer)
	sql.Db, err = gorm.Open(name)
	if err != nil {
		return nil, err
	}

	// make shure its there
	sql.Db.AutoMigrate(&Book{})

	return sql, err
}
