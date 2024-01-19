section .data
	num1:	equ	100
	num2:	equ	50
	msg1:	db	"Sum is correct"
	msg2:	db	"Sum is incorrect"

section .text
	global _start

;; entry point
_start:
	mov		rax, num1
	mov		rbx, num2
	add		rax, rbx		; get sum of rax and rbx, and store the result in rax
	cmp		rax, rbx		; compare rax with rbx
	jne		.incorrectSum	; jump to .exit if not equal
	jmp 	.correctSum		; jump to .correctSum

;; print message that sum is correct
.correctSum:
	;; sys_write(1, msg1, 15)
	mov		rax, 1
	mov		rdi, 1
	mov		rsi, msg1
	mov		rdx, 14
	syscall
	jmp		.exit

;; print message that sum is incorrect
.incorrectSum:
	;; sys_write(1, msg2, 17)
	mov		rax, 1
	mov		rdi, 1
	mov 	rsi, msg2
	mov		rdx, 16
	syscall
	jmp		.exit

;; exit procedure
.exit:
	;; sys_exit(0)
	mov		rax, 60
	mov		rdi, 0
	syscall
