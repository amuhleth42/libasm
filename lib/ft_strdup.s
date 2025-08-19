global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

; rdi <- const char *s

section .text:

ft_strdup:
	.call_strlen:
		push rdi
		call ft_strlen
	.call_malloc:
		lea rdi, [rax + 1]
		sub rsp, 8
		call malloc WRT ..plt
		add rsp, 8
		cmp rax, 0
		je .error
	.call_strcpy:
		mov rdi, rax
		pop rsi
		call ft_strcpy
		ret


	.error:
		xor rax, rax
		pop rdi
		ret


