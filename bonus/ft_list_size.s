global	ft_list_size

section .text

; rdi <- t_list *begin_list
; lst->next -> offset 0
; lst->data -> offset 8

ft_list_size:
	xor eax, eax			; int 32b

.loop:
	cmp rdi, 0
	je .done
	inc eax
	mov rdi, [rdi]
	jmp .loop

.done:
	ret
