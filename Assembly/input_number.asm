section .text
global  main

main:
	mov edx, len_msg1
	mov ecx, msg1
	mov ebx, 0x1
	mov eax, 0x4
	int 0x80

	mov edx, 0x6
	mov ecx, numb
	mov ebx, 0x2
	mov eax, 0x3
	int 0x80

	mov edx, len_msg2
	mov ecx, msg2
	mov ebx, 0x1
	mov eax, 0x4
	int 0x80

	mov edx, 6
	mov ecx, numb
	mov ebx, 0x1
	mov eax, 0x4
	int 0x80

	mov ebx, 0
	mov eax, 1
	int 0x80

	section .bss
	numb    resb 6

	section .data
	msg1    db "Enter a number: "
	len_msg1 equ $ - msg1
	msg2    db  "You enter: "
	len_msg2 equ $ - msg2
