        .text
        .type gemm_asm_asimd_16_4_4, %function
        .global gemm_asm_asimd_16_4_4
        /*
         * Performs the matrix-multiplication C+=A*B
         * with the shapes (16x4) = (16x5) * (4x4).
         * The input-data is of type float.
         *
         * @param x0 pointer to A.
         * @param x1 pointer to B.
         * @param x2 pointer to C.
         */ 
gemm_asm_asimd_16_4_4:
        // store
        stp x19, x20, [sp, #-16]!
        stp x21, x22, [sp, #-16]!
        stp x23, x24, [sp, #-16]!
        stp x25, x26, [sp, #-16]!
        stp x27, x28, [sp, #-16]!
        stp x29, x30, [sp, #-16]!

        stp  d8,  d9, [sp, #-16]!
        stp d10, d11, [sp, #-16]!
        stp d12, d13, [sp, #-16]!
        stp d14, d15, [sp, #-16]!


        // your matrix-kernel goes here!
        
        //loading matrix C
        ld1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v8.4s, v9.4s, v10.4s, v11.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v12.4s, v13.4s, v14.4s, v15.4s}, [x2]
        
        //loading matrix B
        ld1 {v16.4s, v17.4s, v18.4s, v19.4s}, [x1]
        
        //loading first row of A
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        
        //multiply add
        fmla v0.4s, v20.4s, v16.s[0]
        fmla v1.4s, v21.4s, v16.s[0]
        fmla v2.4s, v22.4s, v16.s[0]
        fmla v3.4s, v23.4s, v16.s[0]
        
        fmla v4.4s, v20.4s, v17.s[0]
        fmla v5.4s, v21.4s, v17.s[0]
        fmla v6.4s, v22.4s, v17.s[0]
        fmla v7.4s, v23.4s, v17.s[0]
        
        fmla v8.4s, v20.4s, v18.s[0]
        fmla v9.4s, v21.4s, v18.s[0]
        fmla v10.4s, v22.4s, v18.s[0]
        fmla v11.4s, v23.4s, v18.s[0]
        
        fmla v12.4s, v20.4s, v19.s[0]
        fmla v13.4s, v21.4s, v19.s[0]
        fmla v14.4s, v22.4s, v19.s[0]
        fmla v15.4s, v23.4s, v19.s[0]
        
        
        add x0, x0, #16*4
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        
        fmla v0.4s, v20.4s, v16.s[1]
        fmla v1.4s, v21.4s, v16.s[1]
        fmla v2.4s, v22.4s, v16.s[1]
        fmla v3.4s, v23.4s, v16.s[1]
        
        fmla v4.4s, v20.4s, v17.s[1]
        fmla v5.4s, v21.4s, v17.s[1]
        fmla v6.4s, v22.4s, v17.s[1]
        fmla v7.4s, v23.4s, v17.s[1]
        
        fmla v8.4s, v20.4s, v18.s[1]
        fmla v9.4s, v21.4s, v18.s[1]
        fmla v10.4s, v22.4s, v18.s[1]
        fmla v11.4s, v23.4s, v18.s[1]
        
        fmla v12.4s, v20.4s, v19.s[1]
        fmla v13.4s, v21.4s, v19.s[1]
        fmla v14.4s, v22.4s, v19.s[1]
        fmla v15.4s, v23.4s, v19.s[1]
        
        
        add x0, x0, #16*4
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        
        fmla v0.4s, v20.4s, v16.s[2]
        fmla v1.4s, v21.4s, v16.s[2]
        fmla v2.4s, v22.4s, v16.s[2]
        fmla v3.4s, v23.4s, v16.s[2]
        
        fmla v4.4s, v20.4s, v17.s[2]
        fmla v5.4s, v21.4s, v17.s[2]
        fmla v6.4s, v22.4s, v17.s[2]
        fmla v7.4s, v23.4s, v17.s[2]
        
        fmla v8.4s, v20.4s, v18.s[2]
        fmla v9.4s, v21.4s, v18.s[2]
        fmla v10.4s, v22.4s, v18.s[2]
        fmla v11.4s, v23.4s, v18.s[2]
        
        fmla v12.4s, v20.4s, v19.s[2]
        fmla v13.4s, v21.4s, v19.s[2]
        fmla v14.4s, v22.4s, v19.s[2]
        fmla v15.4s, v23.4s, v19.s[2]
        
        
        add x0, x0, #16*4
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        
        fmla v0.4s, v20.4s, v16.s[3]
        fmla v1.4s, v21.4s, v16.s[3]
        fmla v2.4s, v22.4s, v16.s[3]
        fmla v3.4s, v23.4s, v16.s[3]
        
        fmla v4.4s, v20.4s, v17.s[3]
        fmla v5.4s, v21.4s, v17.s[3]
        fmla v6.4s, v22.4s, v17.s[3]
        fmla v7.4s, v23.4s, v17.s[3]
        
        fmla v8.4s, v20.4s, v18.s[3]
        fmla v9.4s, v21.4s, v18.s[3]
        fmla v10.4s, v22.4s, v18.s[3]
        fmla v11.4s, v23.4s, v18.s[3]
        
        fmla v12.4s, v20.4s, v19.s[3]
        fmla v13.4s, v21.4s, v19.s[3]
        fmla v14.4s, v22.4s, v19.s[3]
        fmla v15.4s, v23.4s, v19.s[3]
        
        //store matrix C
        sub x2, x2, #3*16*4
        st1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #16*4
        st1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #16*4
        st1 {v8.4s, v9.4s, v10.4s, v11.4s}, [x2]
        add x2, x2, #16*4
        st1 {v12.4s, v13.4s, v14.4s, v15.4s}, [x2]
        

        // restore
        ldp d14, d15, [sp], #16
        ldp d12, d13, [sp], #16
        ldp d10, d11, [sp], #16
        ldp  d8,  d9, [sp], #16

        ldp x29, x30, [sp], #16
        ldp x27, x28, [sp], #16
        ldp x25, x26, [sp], #16
        ldp x23, x24, [sp], #16
        ldp x21, x22, [sp], #16
        ldp x19, x20, [sp], #16

        ret
        .size gemm_asm_asimd_16_4_4, (. - gemm_asm_asimd_16_4_4)
