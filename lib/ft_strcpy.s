global ft_strcpy

; rdi <- char *dest
; rsi <- char *src

section .text
	ft_strcpy:
		mov rax, rdi
	.loop:
		mov bl, byte [rsi]
		cmp bl, 0
		je .done
		mov byte [rdi], bl
		inc rdi
		inc rsi
		jmp .loop
	.done:
		mov byte [rdi], 0
		ret
		
		
