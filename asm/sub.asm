;
; sub.asm
; rdi 1st arg , rsi 2nd arg

global sub_v

sub_v:
    sub rdi, rsi
    mov rax, rdi
    ret
