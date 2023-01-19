package main

import (
	"fmt"
	"html/template"
	"log"
	"net/http"
	"strings"

	_ "github.com/go-sql-driver/mysql"
)

type User struct {
	email    string
	username string
	password string
}

type UserList struct {
	data map[string]User
}

type SubmitResponse struct {
	IsSuccess bool
	FailedMsg string
}

var userList UserList = UserList{data: make(map[string]User)}

func checkErr(err error) bool {
	if err != nil {
		panic(err)
		return false
	}
	return true
}

func loginPage(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Method:", r.Method)
	// 加载页面逻辑
	if r.Method == "GET" {
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: true,
			FailedMsg: "",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}

	// 验证表单数据逻辑
	err := r.ParseForm()
	if err != nil {
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "表单解析错误",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}
	// 注册
	if r.Form.Has("email") {
		// 已存在账户名直接返回
		if _, ok := userList.data[r.FormValue("username")]; ok {
			tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "已存在账户名",
			}
			log.Println(tmpl.Execute(w, responseData))
			return
		}
		// 已存在邮箱直接返回
		if _, ok := userList.data[r.FormValue("email")]; ok {
			tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "已存在邮箱",
			}
			log.Println(tmpl.Execute(w, responseData))
			return
		}
		// 注册成功
		userList.data[r.FormValue("username")] = User{
			email:    r.FormValue("email"),
			username: r.FormValue("username"),
			password: r.FormValue("password"),
		}
		fmt.Println(userList.data)
		http.Redirect(w, r, "/home", http.StatusFound)
		return
	}
	// 登录
	// 不存在用户名直接返回
	if _, ok := userList.data[r.FormValue("username")]; !ok {
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "用户名不存在",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}
	// 密码错误直接返回
	if password := userList.data[r.FormValue("username")].password; password != r.FormValue("password") {
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "密码错误",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}
	// 登陆成功
	fmt.Println("用户", r.FormValue("username"), "登陆成功")
	http.Redirect(w, r, "/home", http.StatusFound)
}

func homePage(w http.ResponseWriter, r *http.Request) {
	err := r.ParseForm()
	if err != nil {
		return
	}
	fmt.Println(r.Form)
	fmt.Println("path:", r.URL.Path)
	fmt.Println("scheme:", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("value:", strings.Join(v, ""))
	}
	_, err = fmt.Fprintf(w, "Hello world!")
	if err != nil {
		return
	}
}

func main() {
	mux := http.NewServeMux()
	fs := http.FileServer(http.Dir("./static"))
	mux.Handle("/static/", http.StripPrefix("/static", fs))
	mux.HandleFunc("/login", loginPage)
	mux.HandleFunc("/home", homePage)

	log.Fatal(http.ListenAndServe(":80", mux))
}
