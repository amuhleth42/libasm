global	ft_list_push_front
extern	ft_create_elem

; rdi <- t_list **begin_list
; rsi <- void *data

section	.text

ft_list_push_front:

	cmp rdi, 0
	je .ret

	mov rax, [rdi]
	cmp rax, 0
	jne .not_empty

	push rdi
	mov rdi, rsi
	call ft_create_elem
	pop rdx
	mov [rdx], rax
	ret

.not_empty:
	mov r12, rax			; rcx <- first elem
	push rdi
	mov rdi, rsi
	call ft_create_elem
	pop rdx
	mov [rdx], rax
	cmp rax, 0
	je .ret
	mov [rax], r12
	ret

.ret:
	ret
