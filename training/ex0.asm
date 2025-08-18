global _start

section .data
msg db "Hello, world!", 10
len equ $ - msg

section .text
_start:
    mov rax, 1   	; write syscall
    mov rdi, 1           ; fd = stdout
    lea rsi, [rel msg]   ; buffer
    mov rdx, len         ; length
    syscall

    mov rax, 60   ; exit syscall
    xor rdi, rdi
    syscall
