global	ft_list_size

section .text

ft_list_size:
	xor eax, eax

.loop:
	cmp rdi, 0
	je .done
	inc eax
	mov rdi, [rdi + 8]
	jmp .loop

.done
	ret
