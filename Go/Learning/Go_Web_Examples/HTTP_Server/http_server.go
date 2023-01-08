package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		_, err := fmt.Fprint(w, "Welcome to my Website")
		if err != nil {
			return
		}
	})
	fs := http.FileServer(http.Dir("static/"))
	http.Handle("/static/", http.StripPrefix("/static/", fs))
	err := http.ListenAndServe(":80", nil)
	if err != nil {
		return
	}
}
