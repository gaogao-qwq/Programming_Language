section .data
	SYS_WRITE	equ 1
	STD_OUT		equ 1
	SYS_EXIT	equ 60
	EXIT_CODE	equ 0

	NEW_LINE	db	0xa
	WRONG_ARGC	db	"Must be 2 arguments", 0xa

section .text
	global _start

_start:
	pop		rcx				; get value from rsp (the data at the top of stack that represent argument count)
	cmp		rcx, 3			; compare argument count with 3
	jne		argc_error		; call argc_error if argument count not equal to 3
	add		rsp, 8			; let rsp point (which pointed to the top of stack) to the second data in stack

	pop		rsi				; get first argument
	call	str_to_int		; convert first argument string to int
	mov		r10, rax		; store result in r10

	pop		rsi				; get second argument
	call	str_to_int		; convert second argument string to int
	mov		r11, rax		; store result in r11

	add		r10, r11		; get the sum of arg1 and arg2, store sum in r10
	
	;; Convert int to string
	mov		rax, r10
	xor		r12, r12
	jmp 	int_to_str

argc_error:
	;; sys_write(STD_OUT, WRONG_ARGC, 19)
	mov		rax, SYS_WRITE
	mov		rdi, STD_OUT
	mov		rsi, WRONG_ARGC
	mov		rdx, 20
	syscall
	jmp		exit

str_to_int:
	xor rax, rax				; accumulator
	mov rcx, 10					; base for multiplication
next:
	cmp		[rsi], byte 0		; check if it's the end of string
	je		return_str			; if it's the end, return the string
	mov		bl, [rsi]			; mov current char to bl
	sub		bl, 48				; convert ascii char to number
	mul		rcx					; rax *= 10
	add		rax, rbx			; rax += rbx
	inc		rsi					; get next number
	jmp		next				; loop

int_to_str:
	mov		rdx, 0		; reminder from division
	mov		rbx, 10
	div		rbx			; rax /= 10
	add		rdx, 48		; get char
	push	rdx			; push reminder into stack
	inc		r12			; increment string length
	cmp		rax, 0x0	; check if it's equal to 0
	jne		int_to_str	; if it isn't, loop
	jmp		print		; if it is, print the number

print:
	mov		rax, 1
	mul		r12
	mov		r12, 8
	mul		r12
	mov		rdx, rax

	;; sys_write(STD_OUT, rsp, rdx)
	mov		rax, SYS_WRITE
	mov		rdi, STD_OUT
	mov		rsi, rsp
	syscall
	
	jmp		exit

return_str:
	ret

exit:
	;; sys_exit(EXIT_CODE)
	mov		rax, SYS_EXIT
	mov		rdi, EXIT_CODE
	syscall
