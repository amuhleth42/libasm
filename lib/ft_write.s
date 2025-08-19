global	ft_write
extern	__errno_location

; rdi <- int fd
; rsi <- const void *buf
; rdx <- size_t count

section .text
	ft_write:
		mov rax, 1
		syscall
		ret
