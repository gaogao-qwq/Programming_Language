package handlers

import (
	"crypto/sha256"
	"database/sql"
	"encoding/hex"
	"fmt"
	"html/template"
	"log"
	"login_example/internal/app/server/session"
	_ "login_example/internal/app/server/session/memory"
	"net/http"
	"time"
)

type SubmitResponse struct {
	IsSuccess bool
	FailedMsg string
}

var globalSessions *session.Manager

func init() {
	globalSessions, _ = session.NewManager("memory", "gosessionid", 3600)
	go globalSessions.GC()
}

func checkErr(err error) bool {
	if err != nil {
		return false
	}
	return true
}

// LoginPage 登录页逻辑
func LoginPage(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Method:", r.Method)
	sess := globalSessions.SessionStart(w, r)

	// 加载页面逻辑
	if r.Method == "GET" {
		if sess.Get("username") != nil {
			http.Redirect(w, r, "/home", http.StatusFound)
			return
		}
		tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
		responseData := SubmitResponse{
			IsSuccess: true,
			FailedMsg: "",
		}
		log.Println(tmpl.Execute(w, responseData))
		return
	}

	// 验证表单数据逻辑
	if !checkErr(r.ParseForm()) {
		tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
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
	db, err := sql.Open("mysql", "gaogao-qwq:gaogao-qwq@tcp(192.168.50.159:3306)/test_db?charset=utf8mb4&parseTime=true&loc=Asia%2FShanghai")
	if !checkErr(err) {
		fmt.Println("无法连接至数据库")
		tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
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
		tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
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
		// 已存在邮箱直接返回
		rows, err := db.Query("SELECT * FROM test_db.userinfo WHERE email=?", r.FormValue("email"))
		if !checkErr(err) {
			return
		}
		if rows.Next() {
			tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "已存在邮箱",
			}
			if !checkErr(tmpl.Execute(w, responseData)) {
				fmt.Println("模板执行出错")
			}
			return
		}

		// 已存在账户名直接返回
		rows, err = db.Query("SELECT * FROM test_db.userinfo WHERE username=?", r.FormValue("username"))
		if !checkErr(err) {
			return
		}
		if rows.Next() {
			tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "已存在账户名",
			}
			if !checkErr(tmpl.Execute(w, responseData)) {
				fmt.Println("模板执行错误")
			}
			return
		}

		// 表单录入数据库逻辑
		date := time.Now().String()[0:10]
		fmt.Println("account registered date:", date)
		// 对表单提交的密码执行 SHA-256 加密
		encodedPassword := sha256.Sum256([]byte(r.FormValue("password")))
		// 注册录入数据库逻辑
		stmt, err := db.Prepare("insert test_db.userinfo set email=?,username=?,password=?,created=?")
		if !checkErr(err) {
			return
		}
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
		err = sess.Set("username", r.FormValue("username"))
		if !checkErr(err) {
			return
		}
		err = sess.Set("createtime", time.Now().Unix())
		if !checkErr(err) {
			return
		}
		http.Redirect(w, r, "/home", http.StatusFound)
		return
	}

	// 登录校验处理逻辑
	if !r.Form.Has("email") {
		rows, err := db.Query("SELECT * FROM test_db.userinfo WHERE username=?", r.FormValue("username"))
		if !checkErr(err) {
			return
		}
		// 不存在用户名直接返回
		if !rows.Next() {
			tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "不存在用户名",
			}
			if !checkErr(tmpl.Execute(w, responseData)) {
				fmt.Println("模板执行出错")
			}
			return
		}
		// 在数据库中匹配到表单提交的用户名逻辑
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
		encodedPassword := sha256.Sum256([]byte(r.FormValue("password")))
		// 密码错误直接返回
		if password != hex.EncodeToString(encodedPassword[:]) {
			tmpl := template.Must(template.ParseFiles("web/templates/login-page.gohtml"))
			responseData := SubmitResponse{
				IsSuccess: false,
				FailedMsg: "用户密码错误",
			}
			if !checkErr(tmpl.Execute(w, responseData)) {
				fmt.Println("模板执行出错")
			}
			return
		}
		fmt.Println("用户", r.FormValue("username"), "登陆成功")
		err = sess.Set("username", r.FormValue("username"))
		if !checkErr(err) {
			return
		}
		createTime := sess.Get("createtime")
		if createTime == nil {
			err := sess.Set("createtime", time.Now().Unix())
			if err != nil {
				return
			}
		} else if (createTime.(int64) + 360) < (time.Now().Unix()) {
			globalSessions.SessionDestroy(w, r)
			sess = globalSessions.SessionStart(w, r)
		}
		if !checkErr(err) {
			return
		}
		http.Redirect(w, r, "/home", http.StatusFound)
	}
}

// HomePage 主页逻辑
func HomePage(w http.ResponseWriter, r *http.Request) {
	sess := globalSessions.SessionStart(w, r)
	if sess.Get("username") == nil {
		http.Redirect(w, r, "/login", http.StatusFound)
		return
	}
	createTime := sess.Get("createtime")
	if createTime == nil {
		err := sess.Set("createtime", time.Now().Unix())
		if err != nil {
			return
		}
	} else if (createTime.(int64) + 360) < (time.Now().Unix()) {
		globalSessions.SessionDestroy(w, r)
		http.Redirect(w, r, "/login", http.StatusFound)
		return
	}
	fmt.Println("Method:", r.Method)
	// 加载页面逻辑
	if r.Method == "GET" {
		tmpl := template.Must(template.ParseFiles("web/templates/home-page.gohtml"))
		log.Println(tmpl.Execute(w, sess.Get("username")))
		_, err := fmt.Fprintf(w, "登陆成功")
		if !checkErr(err) {
			fmt.Println("格式化打印至 DOM 错误")
		}
	}
	if r.Method == "POST" {
		globalSessions.SessionDestroy(w, r)
		http.Redirect(w, r, "/login", http.StatusFound)
	}
}
