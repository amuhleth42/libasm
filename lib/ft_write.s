global	ft_write
extern	__errno_location

; rdi <- int fd
; rsi <- const void *buf
; rdx <- size_t count

section .text
	ft_write:
		mov rax, 1
		syscall
		test rax, rax
		js .error
		ret

	.error:
		neg rax
		mov rdx, rax
		call __errno_location WRT ..plt
		mov [rax], rdx
		mov rax, -1
		ret
