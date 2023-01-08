package main

import "fmt"

// Global 全局变量（首字母大写可以被跨包调用）
var Global string = "The Go Programming Language"

func main() {
	// Go 定义变量后必须使用
	var v1 int = 1
	fmt.Printf("v1 = %v\n", v1)
	// Go 拥有类型推断，声明变量时可以省略类型
	v2 := 2
	fmt.Printf("v2 = %v\n", v2)
	// 批量声明
	var (
		v3 string  = "Hello world"
		v4 float64 = 3.14
		v5 []byte  = []byte("Hello world")
	)
	fmt.Printf("v3 = %s\nv4 = %v\nv5 = %s", v3, v4, v5)
	// 常量类似
	const (
		c1 string = "blog.gaogaoqwq.com"
		c2        = iota
		c3
		c4
		c5
	)
	fmt.Printf("c1 = %s\nc2 = %v\nc3 = %v\nc4 = %v\nc5 = %v\n", c1, c2, c3, c4, c5)
	fmt.Printf("Global = %s\n", Global)
}
