section .text
global  main

main:
	mov edx, len_msg
	mov ecx, msg
	mov ebx, 1
	mov eax, 0x4
	int 0x80

	mov ebx, 0
	mov eax, 0x1
	int 0x80

	section .data
	msg     db "Hello, world!!", 0xa
	len_msg equ $ - msg
