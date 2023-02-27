package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("command: " + os.Args[0])
	for i, args := range os.Args[1:] {
		fmt.Printf("%d: %s\n", i, args)
	}
}
