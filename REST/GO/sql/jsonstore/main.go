package main

import (
	"encoding/json"
	mux "github.com/gorilla/mux"
	gorm "github.com/jinzhu/gorm"
	_ "github.com/lib/pq"
	"io/ioutil"
	"log"
	"net/http"
	models "rest/sql/jsonstore/models"
	"time"
)

type DBClient struct {
	db *gorm.DB
}

type UserResponse struct {
	User models.User "json:\"user\""
	Data interface{} "json:\"data\""
}

func (d *DBClient) GetUserByFirstNAme(w http.ResponseWriter, r *http.Request) {
	var users []models.User
	name := r.FormValue("first_name")
	var query string = "select * from \"user\" where data->>'first_name'=?"
	d.db.Raw(query, name).Scan(&users)
	w.WriteHeader(http.StatusOK)
	w.Header().Set("Content-Type", "application/json")
	respJSON, _ := json.Marshal(users)
	w.Write(respJSON)
}

func (d *DBClient) GetUser(w http.ResponseWriter, r *http.Request) {
	var user models.User = models.User{}
	vars := mux.Vars(r)
	d.db.First(&user, vars["id"])
	var userData interface{}

	json.Unmarshal([]byte(user.Data), &userData)
	var response = UserResponse{User: user, Data: userData}
	w.WriteHeader(http.StatusOK)
	w.Header().Add("Content-Type", "application/json")
	respJSON, _ := json.Marshal(response)
	w.Write(respJSON)
}

func (d *DBClient) PostUser(w http.ResponseWriter, r *http.Request) {
	var user models.User = models.User{}
	body, _ := ioutil.ReadAll(r.Body)
	user.Data = string(body)
	d.db.Save(&user)
	responseMap := map[string]interface{}{"id": user.ID}

	var err string = ""

	if err != "" {
		w.Write([]byte("yes"))
	} else {
		w.Header().Set("Content-Type", "application/json")
		response, _ := json.Marshal(responseMap)
		w.Write(response)
	}
}

func main() {
	db, err := models.InitDB("10.43.226.120")
	if err != nil {
		log.Fatalf("Could not init db %s", err)
		return
	}
	defer db.Close()

	dbclient := &DBClient{db: db}
	r := mux.NewRouter()
	r.HandleFunc("/v1/user/{id:[a-zA-Z0-9]*}", dbclient.GetUser).Methods("GET")
	r.HandleFunc("/v1/user/", dbclient.PostUser).Methods("POST")
	r.HandleFunc("/v1/user/", dbclient.GetUserByFirstNAme).Methods("GET")

	s := &http.Server{
		Handler:      r,
		Addr:         "127.0.0.1:8000",
		WriteTimeout: time.Second * 15,
		ReadTimeout:  time.Second * 15,
	}

	log.Fatal(s.ListenAndServe())
}
