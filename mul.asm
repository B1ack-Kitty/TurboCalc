;
; mul.asm
; rdi 1st arg , rsi 2nd arg

global mul_v

mul_v:
    imul rdi, rsi
    mov rax, rdi
    ret
