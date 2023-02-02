package sqldb

import (
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

type Book struct {
	Id     string `json:string,omitempty`
	Name   string `json:name,omitmepty`
	Author string `json:author, omitempty`
}

func New_Book(name string, author string) *Book {
	return &Book{
		Name:   name,
		Author: author,
	}
}

type SQLServer struct {
	Db *gorm.DB
}

func (s *SQLServer) GetBookId(id *string) *[]Book {
	var book []Book
	s.Db.Find(&book, id)
	return &book
}

func (s *SQLServer) GetBookAuthor(author *string) *[]Book {
	var book []Book
	s.Db.Find(&book, "Author=?", author)
	return &book
}

func (s *SQLServer) GetBooks() *[]Book {
	var book []Book
	s.Db.Find(&book)
	return &book
}

func (s *SQLServer) ADDBook(b *Book) {
	s.Db.Create(b)
}

func New(name string) (*SQLServer, error) {
	var err error = nil

	sql := new(SQLServer)
	sql.Db, err = gorm.Open(sqlite.Open(name), &gorm.Config{})
	if err != nil {
		return nil, err
	}

	// make shure its there
	sql.Db.AutoMigrate(&Book{})

	return sql, err
}
