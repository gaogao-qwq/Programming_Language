package main

import (
	_ "github.com/go-sql-driver/mysql"
	"log"
	"login_example/internal/app/server/handlers"
	"net/http"
)

func main() {
	fs := http.FileServer(http.Dir("./web/static"))
	mux := http.NewServeMux()
	mux.Handle("/web/static/", http.StripPrefix("/web/static", fs))
	mux.HandleFunc("/login", handlers.LoginPage)
	mux.HandleFunc("/home", handlers.HomePage)

	log.Fatal(http.ListenAndServe(":80", mux))
}
