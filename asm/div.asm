;
; div.asm
; rdi 1st arg , rsi 2nd arg

global div_v

div_v:
    mov rax, rdi
    cqo
    idiv rsi
    ret
