global str_len

str_len:
    mov rax, 0
    call start_loop


start_loop:
    cmp [rdi], byte 0   ; condition
    jle exit_loop       ; conditional exit
    inc rdi
    inc rax
    jmp start_loop

exit_loop:
    ret
