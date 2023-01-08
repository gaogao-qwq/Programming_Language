package main

import "fmt"

func main() {
	// 格式字符（和 C 类似）
	i := 114514
	c := '我'
	f := 3.1415926
	str := "Hello 世界"
	ptr := &str
	// 通用 %v %T
	fmt.Printf("i = %v, type is %T\n", i, i)
	// 整数 %d %b %o %x %X %U %c %q
	fmt.Printf("i(decimal) = %d\n", i)
	fmt.Printf("i(binary) = %b\n", i)
	fmt.Printf("i(octal) = %o\n", i)
	fmt.Printf("i(hexadecimal-lower-case) = 0x%x, i(hexadecimal-higher-case) = 0X%X\n", i, i)
	fmt.Printf("c(Character) = %c, c(Unicode) = %U, c(quoted) = %q\n", c, c, c)
	// 浮点数 %f %.nf %wf %w.nf %b %e %E %g %G %x %X
	fmt.Printf("f = %5.2f\n", f)
	fmt.Printf("f = %b\n", f)
	fmt.Printf("f = %e, f = %E\n", f, f)
	fmt.Printf("f(hexadecimal-lower-case) = %x, f(hexadecimal-higher-case) = %X\n", f, f)
	// 布尔值 %t
	fmt.Printf("%t\t%t\n", true, false)
	// 字符串 %s %q %x %X
	fmt.Printf("str = %s, str(quoted) = %q\n", str, str)
	fmt.Printf("str(hexadecimal-lower-case) = %x str(hexadecimal-higher-case) = %X\n", str, str)
	// 指针 %p
	fmt.Printf("ptr = %p\n", ptr)
}
