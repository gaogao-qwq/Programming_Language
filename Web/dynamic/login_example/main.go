package main

import (
	"crypto/sha256"
	"database/sql"
	"encoding/hex"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"html/template"
	"log"
	"net/http"
	"time"
)

type SubmitResponse struct {
	IsSuccess bool
	FailedMsg string
}

func checkErr(err error) bool {
	if err != nil {
		panic(err)
		return false
	}
	return true
}

// 登录页逻辑
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
	if !checkErr(r.ParseForm()) {
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "表单解析错误",
		}
		if !checkErr(tmpl.Execute(w, responseData)) {
			fmt.Println("模板执行出错")
		}
		return
	}

	// 连接数据库
	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/test_db?charset=utf8mb4&parseTime=true&loc=Asia%2FShanghai")
	if !checkErr(err) {
		fmt.Println("无法连接至数据库")
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "无法连接至数据库",
		}
		if !checkErr(tmpl.Execute(w, responseData)) {
			fmt.Println("模板执行出错")
		}
		if !checkErr(db.Close()) {
			fmt.Println("终止数据库连接失败")
		}
		return
	}

	// 获取 Rows
	rows, err := db.Query("SELECT * FROM test_db.userinfo")
	if !checkErr(err) {
		fmt.Println("数据库中没有 userinfo 表")
		tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: false,
			FailedMsg: "数据库表缺失",
		}
		if !checkErr(tmpl.Execute(w, responseData)) {
			fmt.Println("模板执行出错")
		}
		return
	}
	// 释放 Rows
	defer func(rows *sql.Rows) {
		err := rows.Close()
		if !checkErr(err) {
			fmt.Println("释放 Rows 错误")
		}
	}(rows)

	// 注册校验处理逻辑
	if r.Form.Has("email") {
		for rows.Next() {
			var (
				uid      int
				email    string
				username string
				password string
				date     string
			)
			if !checkErr(rows.Scan(&uid, &email, &username, &password, &date)) {
				return
			}
			// 已存在账户名直接返回
			if username == r.FormValue("username") {
				tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
				responseData := SubmitResponse{
					IsSuccess: false,
					FailedMsg: "已存在账户名",
				}
				if !checkErr(tmpl.Execute(w, responseData)) {
					fmt.Println("模板执行出错")
				}
				return
			}
			// 已存在邮箱直接返回
			if email == r.FormValue("email") {
				tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
				responseData := SubmitResponse{
					IsSuccess: false,
					FailedMsg: "已存在邮箱",
				}
				if !checkErr(tmpl.Execute(w, responseData)) {
					fmt.Println("模板执行出错")
				}
				return
			}
		}
		// 获取注册时间
		date := time.Now().String()[0:10]
		fmt.Println("account registered date:", date)
		// 对表单提交的密码执行 SHA-256 加密
		encodedPassword := sha256.Sum256([]byte(r.FormValue("password")))
		// 注册录入数据库逻辑
		stmt, err := db.Prepare("insert test_db.userinfo set email=?,username=?,password=?,created=?")
		res, err := stmt.Exec(
			r.FormValue("email"),
			r.FormValue("username"),
			hex.EncodeToString(encodedPassword[:]),
			date,
		)
		if !checkErr(err) {
			return
		}
		id, err := res.LastInsertId()
		if !checkErr(err) {
			return
		}
		fmt.Println("username:", r.FormValue("username"), "id:", id, "注册成功")
		if !checkErr(err) {
			return
		}
		http.Redirect(w, r, "/home", http.StatusFound)
		return
	}

	// 登录校验处理逻辑
	if !r.Form.Has("email") {
		// 在数据库中匹配到表单提交的用户名逻辑
		for rows.Next() {
			var (
				uid      int
				email    string
				username string
				password string
				date     string
			)
			if !checkErr(rows.Scan(&uid, &email, &username, &password, &date)) {
				return
			}
			if username == r.FormValue("username") {
				// 对表单提交的密码进行 SHA-256 加密后与数据库中储存的密码进行匹配
				encodedPassword := sha256.Sum256([]byte(r.FormValue("password")))
				if password == hex.EncodeToString(encodedPassword[:]) {
					// 登陆成功
					fmt.Println("用户", r.FormValue("username"), "登陆成功")
					http.Redirect(w, r, "/home", http.StatusFound)
					return
				} else {
					// 密码错误直接返回
					tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
					responseData := SubmitResponse{
						IsSuccess: false,
						FailedMsg: "用户密码错误",
					}
					if !checkErr(tmpl.Execute(w, responseData)) {
						fmt.Println("模板执行出错")
					}
					return
				}
			}
		}
	}
	// 不存在用户名直接返回
	tmpl := template.Must(template.ParseFiles("templates/login-page.gohtml"))
	responseData := SubmitResponse{
		IsSuccess: false,
		FailedMsg: "不存在用户名",
	}
	if !checkErr(tmpl.Execute(w, responseData)) {
		fmt.Println("模板执行出错")
	}
	return
}

// 注液逻辑
func homePage(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Method:", r.Method)
	// 加载页面逻辑
	if r.Method == "GET" {
		tmpl := template.Must(template.ParseFiles("templates/home-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: true,
			FailedMsg: "",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}
	_, err := fmt.Fprintf(w, "登陆成功")
	if !checkErr(err) {
		fmt.Println("格式化打印至 DOM 错误")
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
