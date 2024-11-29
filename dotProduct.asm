section .text
bits 64
default rel
global dot_prod

dot_prod:
    xorps xmm5, xmm5
    xor rsi, rsi

DOT_LOOP:
    cmp rsi, r8
    jge END
    
    movss xmm0, [rcx + rsi * 4]
    movss xmm1, [rdx + rsi * 4]
    
    mulss xmm0, xmm1
    
    addss xmm5, xmm0
        
    inc rsi
    jmp DOT_LOOP

END:
    movss xmm0, xmm5
    ret