global _main

section .data
msg: db "Hello, world!", 10
len: equ $ - msg

section .text
_main:
    mov rax, 0x2000004   ; write syscall
    mov rdi, 1           ; fd = stdout
    lea rsi, [rel msg]   ; buffer
    mov rdx, len         ; length
    syscall

    mov rax, 0x2000001   ; exit syscall
    xor rdi, rdi
    syscall
