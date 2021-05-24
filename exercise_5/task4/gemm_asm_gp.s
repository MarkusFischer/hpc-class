	.text
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

        // loading matrix B
        //
        // w3 w5
        // w4 w6
        //
        ldp w3, w4, [x1], #8
        ldp w5, w6, [x1], #8
        
        // loading matrix A
        //
        // w7  w11
        // w8  w12
        // w9  w13
        // w10 w14
        //
        ldp w7, w8, [x0], #8
        ldp w9, w10, [x0], #8
        ldp w11, w12, [x0], #8
        ldp w13, w14, [x0], #8
        
        // loading matrix C
        //
        // w15 w19
        // w16 w20
        // w17 w21
        // w18 w22
        //
        ldp w15, w16, [x2], #8
        ldp w17, w18, [x2], #8
        ldp w19, w20, [x2], #8
        ldp w21, w22, [x2], #-32
       
        
        // C_11 (w15)
        madd w15, w7, w3, w15
        madd w15, w11, w4, w15
        
        // C_21 (w16)
        madd w16, w8, w3, w16
        madd w16, w12, w4, w16
        
        // C_31 (w17)
        madd w17, w9, w3, w17
        madd w17, w13, w4, w17
        
        // C_41 (w18)
        madd w18, w10, w3, w18
        madd w18, w14, w4, w18
        
        
        // C_12 (w19)
        madd w19, w7, w5, w19
        madd w19, w11, w6, w19
        
        // C_22 (w20)
        madd w20, w8, w5, w20
        madd w20, w12, w6, w20
        
        // C_32 (w21)
        madd w21, w9, w5, w21
        madd w21, w13, w6, w21
        
        // C_42 (w22)
        madd w22, w10, w5, w22
        madd w22, w14, w6, w22
        
        
        //Storing Matrix C
        // loading matrix C
        //
        // w15 w19
        // w16 w20
        // w17 w21
        // w18 w22
        //
        stp w15, w16, [x2], #8
        stp w17, w18, [x2], #8
        stp w19, w20, [x2], #8
        stp w21, w22, [x2], #8
        
        // restore
        ldp x29, x30, [sp], #16
        ldp x27, x28, [sp], #16
        ldp x25, x26, [sp], #16
        ldp x23, x24, [sp], #16
        ldp x21, x22, [sp], #16
        ldp x19, x20, [sp], #16

        ret
        .size gemm_asm_gp, (. - gemm_asm_gp)
