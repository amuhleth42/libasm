global ft_read
extern __errno_location

; rdi <- int fd
; rsi <- void *buf
; rdx <- size_t count

section .text
	ft_read:
		mov rax, 0
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
