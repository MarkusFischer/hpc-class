    .text
    .align 4
    .type sve_example_0, %function
    .global sve_example_0
sve_example_0:
    ldr z0, [x0]
    str z0, [x1]
    ret

    .type sve_example_2, %function
    .global sve_example_2
sve_example_2:
    ptrue p0.s, VL8
    ld1w {z0.s}, p0/z, [x0]
    str z0, [x1]
    ret