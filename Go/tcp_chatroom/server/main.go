package main

import (
	"fmt"
	"net"
	"strings"
)

// 建立连接的客户端
type Client struct {
	conn     net.Conn
	nickname string
}

var clients []*Client

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
		// 接收客户端连接
		conn, err := listener.Accept()
		fmt.Println("New connection established from:", conn.RemoteAddr().String())
		if err != nil {
			fmt.Println("Error accepting connection:", err)
			break
		}

		// 获取客户端昵称
		buf := make([]byte, 1024)
		n, err := conn.Read(buf)
		if err != nil {
			fmt.Println("Error reading nickname", err)
			conn.Close()
			continue
		}
		nickname := strings.TrimSpace(string(buf[:n]))
		conn.Write([]byte(fmt.Sprintln("Welcome back,", nickname)))

		// 重复昵称校验
		if !isNickNameUnique(nickname) {
			conn.Write([]byte("Nickname is not unique. Please enter another nickname.\n"))
			conn.Close()
			continue
		}

		// 创建客户端实例并加入客户端列表
		client := &Client{conn, nickname}
		clients = append(clients, client)

		// 起一个协程处理客户端
		go handleClient(client)
	}
}

func handleClient(client *Client) {
	defer client.conn.Close()

	clientAddr := client.conn.RemoteAddr().String()
	fmt.Println("Accepted connection from:", clientAddr)

	// 读取客户端消息并广播给所有其它客户端
	buffer := make([]byte, 1024)
	for {
		n, err := client.conn.Read(buffer)
		if err != nil {
			fmt.Printf("Error reading from %s (%s): %s\n", client.nickname, clientAddr, err)
			break
		}
		msg := string(buffer[:n])
		fmt.Printf("Received message from %s (%s): %s\n", client.nickname, clientAddr, msg)

		// 广播给其他客户端
		go broadcastMessage(client, msg)
	}
}

func broadcastMessage(sender *Client, msg string) {
	for _, client := range clients {
		if client != sender {
			client.conn.Write([]byte(fmt.Sprintf("%s (%s): %s", sender.nickname, sender.conn.RemoteAddr(), msg)))
		}
	}
}

func isNickNameUnique(nickname string) bool {
	for _, client := range clients {
		if client.nickname == nickname {
			return false
		}
	}
	return true
}
