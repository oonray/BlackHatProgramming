package models

import (
	"fmt"
	"github.com/jinzhu/gorm"
	_ "github.com/lib/pq"
)

type User struct {
	gorm.Model
	Orders []Order
	Data   string `sql:"type:JSONB NOT NULL DEFAULT '{}'::JSONB" json:"-"`
}

type Order struct {
	gorm.Model
	User User
	Data string `sql:"type:JSONB NOT NULL DEFAULT '{}'::JSONB"`
}

// Change the name of the table
// Override the name
func (User) TableName() string {
	return "user"
}

func (Order) TableName() string {
	return "order"
}

func InitDB(server string) (*gorm.DB, error) {
	var err error
	db, err := gorm.Open("postgres", fmt.Sprintf("postgres://admin:3I5y&DeR4H@BHdcD2iI@%s/postgresdb?sslmode=disable", server))
	if err != nil {
		return nil, err
	}

	if !db.HasTable("user") {
		db.CreateTable(&User{})
	}

	if !db.HasTable("order") {
		db.CreateTable(&Order{})
	}

	db.AutoMigrate(&User{}, &Order{})
	return db, nil
}
