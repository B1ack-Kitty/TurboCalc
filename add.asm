;
; add.asm
; rdi 1st arg , rsi 2nd arg

global add_v

add_v:
    add rdi, rsi
    mov rax, rdi
    ret
