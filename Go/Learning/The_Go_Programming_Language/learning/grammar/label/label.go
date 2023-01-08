package main

func main() {
	// 标签可以让你在多层嵌套中想去哪就去哪
outside:
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			print("* ")
			if i == 9 && j == 4 {
				break outside
			}
		}
		println()
	}
	// 但是因为众所周知的原因，并不建议使用 goto
}
