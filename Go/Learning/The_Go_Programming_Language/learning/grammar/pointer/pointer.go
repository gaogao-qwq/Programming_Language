package main

import "fmt"

func swap(a *int, b *int) {
	*a = *a ^ *b
	*b = *a ^ *b
	*a = *a ^ *b
}

func main() {
	// 和 C 的指针完全一致
	var (
		v1 int  = 114
		v2 int  = 514
		p1 *int = &v1
		p2 *int = &v2
		p3 *int
	)
	fmt.Printf("v1 = %v, p1 = %v, v2 = %v, p2 = %v\n", v1, p1, v2, p2)
	swap(p1, p2) // 传入地址
	fmt.Printf("v1 = %v, p1 = %v, v2 = %v, p2 = %v\n", v1, p1, v2, p2)
	// 指针未初始化时默认值为 nil
	fmt.Printf("p3 = %v", p3)
}
