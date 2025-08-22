global	ft_list_sort

; rdi <- t_list **begin_list
; rsi <- int (*cmp)()

; rdx <- int swapped

section .text

ft_list_sort:
	cmp rdi, 0
	je .ret

	cmp qword [rdi], 0
	je .ret

	mov rax, [rdi]		; rax <- *begin_list
	cmp qword [rax], 0
	je .ret

.big_loop:
	xor rdx, rdx
	mov r12, rax

.small_loop:
	cmp qword [r12], 0
	je .big_loop

.call_cmp:
	mov rdi, [r12 + 8]
	mov rdx, [r12]
	mov rsi, [rdx + 8]
	call 
	

end_small_loop:

	




.ret:
	ret
