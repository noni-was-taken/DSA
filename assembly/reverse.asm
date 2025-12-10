org 100h

start:
    mov dx, OFFSET buffer
    mov ah, 0Ah
    int 21h

    mov cl, [buffer+1]        ; number of chars read
    xor ch, ch
    jcxz done                 ; if empty, exit

    lea si, [buffer+2]        ; pointer to first char

push_loop:
    mov al, [si]
    push ax                   ; push char onto stack
    inc si
    loop push_loop

    ; now pop and print each char
    mov cl, [buffer+1]
    xor ch, ch

pop_loop:
    pop ax
    mov dl, al
    mov ah, 02h               ; DOS print char
    int 21h
    loop pop_loop

done:
    ret

; -------------------------
; DATA
; -------------------------
buffer db 20,0,20 dup(0)

end start