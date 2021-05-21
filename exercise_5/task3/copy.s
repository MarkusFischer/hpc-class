        .text
        .align 4
        .type   copy_asm, %function
        .global copy_asm
copy_asm:
        // copy values 1 and 2
        ldp w2, w3, [x0] #16
        stp x2, x3, [x1] #16
        
        // copy values 3 and 4
        ldp w2, w3, [x0] #16
        stp x2, x3, [x1] #16
        
        // copy values 5 and 6
        ldp w2, w3, [x0] #16
        stp x2, x3, [x1] #16
        
        // copy last value (7)
        ldr w2, [x0]
        str w2, [x1]
        ret
        .size copy_asm, (. - copy_asm)
