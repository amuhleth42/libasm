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

.not_empty
; to do
	mov rdx rax
	push rdi
	mov rdi, rsi
	call ft_create_elem
	pop rcx
	mov [rcx], rax
	cmp rax, 0
	je .ret
	mov [rax], rdx

.ret
	ret
