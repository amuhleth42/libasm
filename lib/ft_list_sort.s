global	ft_list_sort

; rdi <- t_list **begin_list
; rsi <- int (*cmp)()

; rdx <- int swapped
section .text

ft_list_sort:
	cmp rdi, 0
	je .ret

	cmp [rdi], 0
	je .ret

	mov rax, [rdi]
	cmp [rax], 0
	je .ret

.big_loop:
	xor rdx, rdx

.small_loop:
	cmp [rax], 0
	je .big_loop

	




.ret:
	ret
