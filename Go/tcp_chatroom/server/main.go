package main

import (
	"fmt"
	"net"
)

var clients []net.Conn

func main() {
	// 监听端口
	listener, err := net.Listen("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("Error listening", err)
		return
	}
	defer listener.Close()
	fmt.Println("Chat server listening on 127.0.0.1:8080")

	for {
		// 接受客户端连接
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Error accepting connection: ", err)
			break
		}

		// 将连接加入客户端列表
		clients = append(clients, conn)

		go handleClient(conn)
	}
}

func handleClient(conn net.Conn) {
	defer conn.Close()

	clientAddr := conn.RemoteAddr().String()
	fmt.Println("Accepted connection from", clientAddr)

	// 读取客户端消息并广播给所有其它客户端
	buffer := make([]byte, 1024)
	for {
		n, err := conn.Read(buffer)
		if err != nil {
			fmt.Printf("Error reading from %s: %s\n", clientAddr, err)
			break
		}
		msg := string(buffer[:n])
		fmt.Printf("Received message from %s: %s\n", clientAddr, msg)

		// 广播给其他客户端
		go broadcastMessage(conn, msg)
	}
}

func broadcastMessage(sender net.Conn, msg string) {
	for _, client := range clients {
		if client != sender {
			client.Write([]byte(msg))
		}
	}
}
