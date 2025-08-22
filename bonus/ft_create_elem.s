global	ft_create_elem
extern malloc

; rdi <- void *data

section .text

ft_create_elem:
	push rdi

	mov rdi, 16
	call malloc WRT ..plt
	cmp rax, 0
	je .error

	mov qword [rax], 0
	pop rsi
	mov [rax + 8], rsi
	ret
	

.error:
	pop rdi
	ret
