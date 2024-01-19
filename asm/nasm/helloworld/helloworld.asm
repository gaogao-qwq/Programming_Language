section .data
	msg db		"hello, world!"

section .text
	global _start

_start:
	;; sys_write(1, msg, 13)
	mov		rax, 1
	mov		rdi, 1
	mov		rsi, msg
	mov		rdx, 13
	syscall
	;; sys_exit(0)
	mov		rax, 60
	mov		rdi, 0
	syscall
