package main

import "fmt"

func main() {
	age := 0
	print("请输入年龄：")
	_, err := fmt.Scanf("%d", &age)
	if err != nil {
		return
	}
	
	// if...else
	if age >= 18 {
		println("成年")
	} else {
		println("未成年")
	}

	// switch...case
	switch {
	case age < 12:
		println("儿童")
	case age < 18:
		println("青少年")
	default:
		println("成年人")
	}
}
