package main

func main() {
	// Go 中只有 for 循环，但有三种写法
	// 死循环
	v1 := 0
	for {
		print(v1, " ")
		if v1 == 10 {
			break
		}
		v1++
	}
	println()
	// 条件循环（while）
	v2 := 0
	for v2 < 10 {
		if v2%2 == 0 {
			print(v2, " ")
		}
		v2++
	}
	println()
	// 标准 for 循环
	arr := make([]int, 10)
	for i := 0; i < len(arr); i++ {
		arr[i] = i + 1
	}
	// 对于 数组、切片、map等，可以使用 for...range 遍历
	for _, i := range arr {
		print(i, " ")
	}
	println()
}
