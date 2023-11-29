package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

func main() {
	// 连接服务器
	conn, err := net.Dial("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("Error connecting to server: ", err)
		return
	}
	defer conn.Close()

	// 输入昵称
	fmt.Print("Enter your nickname: ")
	scn := bufio.NewScanner(os.Stdin)
	scn.Scan()
	nickname := scn.Text()
	conn.Write([]byte(nickname))

	buf := make([]byte, 1024)
	n, err := conn.Read(buf)
	if err != nil {
		fmt.Println("Error reading welcome from server", err)
		return
	}
	fmt.Println(string(buf[:n]))

	// 起一个协程接收信息
	go readMessage(conn)
	// 发送信息
	sendMessage(conn)
}

func readMessage(conn net.Conn) {
	buf := make([]byte, 1024)
	for {
		n, err := conn.Read(buf)
		if err != nil {
			fmt.Println("Error reading from server", err)
			break
		}
		fmt.Println("\nReceived message from", string(buf[:n]))
		fmt.Print("Enter message: ")
	}
}

func sendMessage(conn net.Conn) {
	scn := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("Enter message: ")
		scn.Scan()
		msg := scn.Text()

		_, err := conn.Write([]byte(msg))
		if err != nil {
			fmt.Println("Error writing to server", err)
			break
		}
	}
}
