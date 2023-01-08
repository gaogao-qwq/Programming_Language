package main

import (
	"fmt"
	"net/http"
)

// 创建一个 handler 函数用于接收来自浏览器、HTTP客户端或API请求的所有传入HTTP连接。
// 该函数接收两个参数：
// 一个 http.ResponseWriter，您可以在其中编写文本/html响应。
// 一个 http.Request，它包含有关此 HTTP 请求的所有信息，包括 URL 或标头字段等内容。
// 当然这里也可以直接写成匿名函数直接写到 http.HandleFunc() 中
func handler(w http.ResponseWriter, r *http.Request) {
	_, err := fmt.Fprintf(w, "Hello, you've requested: %s\n", r.URL.Path)
	if err != nil {
		return
	}
}

func main() {
	// 向默认 HTTP 服务器注册 handler 函数
	http.HandleFunc("/", handler)
	// Request Handler 本身并不能接收来自外部的 HTTP 连接，HTTP 服务器必须监听一个端口，以便将连接传递给 Request Handler
	// 监听 :80 端口（http默认端口）
	err := http.ListenAndServe(":80", nil)
	if err != nil {
		return
	}
}
