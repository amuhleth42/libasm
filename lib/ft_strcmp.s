global ft_strcmp

section .text
	ft_strcmp:
		
	.loop:
		mov al, byte [rdi]
		mov bl, byte [rsi]
		cmp al, 0
		je .done
		cmp bl, 0
		je .done
		cmp al, bl
		jne .done
		
		inc rdi
		inc rsi
		jmp .loop
	.done:
		movzx rax, al
		movzx rbx, bl
		sub rax, rbx
		ret
		
