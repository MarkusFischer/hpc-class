        .text
        .align 4
        .type   load_asm, %function
        .global load_asm
load_asm:
        ldr x1,     [x0, #8]!
        ldp x2, x3, [x0]
        ldp x4, x5, [x0, #16]

        ret
        .size load_asm, (. - load_asm)
