text
        .type gemm_asm_gp, %function
        .global gemm_asm_gp
        /*
         * Performs the matrix-multiplication C+=A*B
         * with the shapes (4x2) = (4x2) * (2x2).
         * The input-data is of type uint32_t.
         *
         * @param x0 pointer to A.
         * @param x1 pointer to B.
         * @param x2 pointer to C.
         */ 
gemm_asm_gp:
        // store
        stp x19, x20, [sp, #-16]!
        stp x21, x22, [sp, #-16]!
        stp x23, x24, [sp, #-16]!
        stp x25, x26, [sp, #-16]!
        stp x27, x28, [sp, #-16]!
        stp x29, x30, [sp, #-16]!

        // your matrix-kernel goes here!

        // C_11
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0]
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_21
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_31
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_41
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        
        // C_12
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #-32]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1, #16]!
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_22
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_32
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // C_42
        // load value of C
        ldr w3, [x2]
        // load row of A
        ldr w4, [x0, #8]!
        ldr w5, [x0, #40]
        // load column of B
        ldp w6, w7, [x1]
        madd w3, w4, w6, w3
        madd w3, w5, w7, w3
        str w3, [x2], #8
        
        // restore
        ldp x29, x30, [sp], #16
        ldp x27, x28, [sp], #16
        ldp x25, x26, [sp], #16
        ldp x23, x24, [sp], #16
        ldp x21, x22, [sp], #16
        ldp x19, x20, [sp], #16

        ret
        .size gemm_asm_gp, (. - gemm_asm_gp)
