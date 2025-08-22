global	ft_list_sort

; rdi, r12 <- t_list **begin_list
; rsi, r13 <- int (*cmp)()

; r15 <- int swapped

section .text

ft_list_sort:
	
	push r12
	push r13
	push r14
	push r15

	cmp rdi, 0
	je .ret

	cmp qword [rdi], 0
	je .ret

	mov r12, rdi
	mov r13, rsi
	mov r15, 1

	mov rax, [rdi]		; rax <- *begin_list
	cmp qword [rax], 0
	je .ret

.big_loop:
	cmp r15, 0
	je .ret

	xor r15, r15
	mov r14, [r12]

.small_loop:
	cmp qword [r14], 0
	je .big_loop

.call_cmp:
	mov rdi, [r14 + 8]
	mov rdx, [r14]
	mov rsi, [rdx + 8]
	call r13

	cmp eax, 0
	jng .increment
	
	mov rax, [r14 + 8]
	mov rdx, [r14]
	mov rcx, [rdx + 8]
	mov [r14 + 8], rcx
	mov [rdx + 8], rax
	inc r15
	

.increment:
	mov r14, [r14]
	jmp .small_loop


.ret:
	pop r15
	pop r14
	pop r13
	pop r12
	ret
