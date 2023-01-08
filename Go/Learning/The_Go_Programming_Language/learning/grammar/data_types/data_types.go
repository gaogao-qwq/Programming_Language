package main

import "fmt"

func main() {
	// int 型
	var (
		i1       = 0b0101 // 0b 二进制
		i2 int8  = 0o77   // 0o 八进制
		i3 int64 = 0xAf   // 0x 十六进制
	)
	fmt.Printf("i1 = %v, type is %T\n", i1, i1)
	fmt.Printf("i2 = %v, type is %T\n", i2, i2)
	fmt.Printf("i2 = %v, type is %T\n", i3, i3)
	// float 型
	var (
		f1         = 1.0
		f2 float32 = 2.17
	)
	fmt.Printf("f1 = %v, type is %T\n", f1, f1)
	fmt.Printf("f2 = %v, type is %T\n", f2, f2)
	// 字符型（实际上就是 int）
	var (
		c1      = 'c' // 默认为 rune
		c2 byte = '0' // byte: ASCII uint8 的别名
		c3 rune = '我' // rune: UTF-8 int32 的别名
	)
	fmt.Printf("c1 = %v, 对应字符是 %c, type is %T\n", c1, c1, c1)
	fmt.Printf("c2 = %v, 对应字符是 %c, type is %T\n", c2, c2, c2)
	fmt.Printf("c3 = %v, 对应字符是 %c, type is %T\n", c3, c3, c3)
	// bool 型
	var b bool = true
	fmt.Printf("b = %v, type is %T\n", b, b)
	// string 型 （底层实际上是 []rune，即 rune 切片，所以一个中文字符长度为3）
	var s string = "Hello 世界！"
	fmt.Printf("s = %v, type is %T\n, len(s) = %v", s, s, len(s))
}
