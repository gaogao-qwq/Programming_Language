package main

import (
	"fmt"
	"github.com/gorilla/mux"
	"net/http"
)

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/books/{title}/page/{page}", func(w http.ResponseWriter, r *http.Request) {
		vars := mux.Vars(r)
		title := vars["title"] // the book title slug
		page := vars["page"]   // the page

		_, err := fmt.Fprintf(w, "You've requested the book: %s on page %s\n", title, page)
		if err != nil {
			return
		}
	})
	err := http.ListenAndServe(":80", r)
	if err != nil {
		return
	}
}
