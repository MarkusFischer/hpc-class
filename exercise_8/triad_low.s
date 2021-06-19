    .text
    .align 4
    .type triad_low, %function
    .global triad_low
triad_low:
    mov x4, #0
    whilelt p0.s, x4, x0
    b.none do_nothing
    fmov z2.s, #2

loop:
    ld1w {z0.s}, p0/z, [x1, x4, lsl #2]
    ld1w {z1.s}, p0/z, [x2, x4, lsl #2]
    fmla z0.s, z1.s, z2.s
    st1w {z0.s}, p0, [x3, x4, lsl #2]
    incw x4
    whilelt p0.s, x4, x0
    b.any loop 

do_nothing:
    ret