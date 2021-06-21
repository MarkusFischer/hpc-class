    .text
    .align 4

    .type fmlalb_example, %function
    .global fmlalb_example
fmlalb_example:
    ldr z0, [x0]
    ldr z1, [x1]
    ldr z3, [x2]
    fmlalb z3.s, z1.h, z0.h
    str z3, [x2]
    ret

    .type fmlalt_example, %function
    .global fmlalt_example
fmlalt_example:
    ldr z0, [x0]
    ldr z1, [x1]
    ldr z3, [x2]
    fmlalt z3.s, z1.h, z0.h
    str z3, [x2]
    ret

    .type udot_example, %function
    .global udot_example
udot_example:
    ldr z0, [x0]
    ldr z1, [x1]
    udot z3.s, z1.b, z0.b
    str z3, [x2]    
    ret