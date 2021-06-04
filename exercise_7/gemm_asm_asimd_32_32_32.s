        .text
        .type gemm_asm_asimd_32_32_32, %function
        .global gemm_asm_asimd_32_32_32
        /*
         * Performs the matrix-multiplication C+=A*B
         * with the shapes (16x4) = (16x5) * (4x4).
         * The input-data is of type float.
         *
         * @param x0 pointer to A.
         * @param x1 pointer to B.
         * @param x2 pointer to C.
         */ 
gemm_asm_asimd_32_32_32:
        
        //loading matrix C
        ld1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v24.4s, v25.4s, v26.4s, v27.4s}, [x2]
        add x2, x2, #16*4
        ld1 {v28.4s, v29.4s, v30.4s, v31.4s}, [x2]
        sub x2, x2, #3*16*4
        
        //loading matrix B
        ld1 {v16.4s, v17.4s, v18.4s, v19.4s}, [x1]
        
        //loading first row of A
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        add x0, x0, #16*4

        //multiply add
        fmla v0.4s, v20.4s, v16.s[0]
        fmla v1.4s, v21.4s, v16.s[0]
        fmla v2.4s, v22.4s, v16.s[0]
        fmla v3.4s, v23.4s, v16.s[0]
        
        fmla v4.4s, v20.4s, v17.s[0]
        fmla v5.4s, v21.4s, v17.s[0]
        fmla v6.4s, v22.4s, v17.s[0]
        fmla v7.4s, v23.4s, v17.s[0]
        
        fmla v24.4s, v20.4s, v18.s[0]
        fmla v25.4s, v21.4s, v18.s[0]
        fmla v26.4s, v22.4s, v18.s[0]
        fmla v27.4s, v23.4s, v18.s[0]
        
        fmla v28.4s, v20.4s, v19.s[0]
        fmla v29.4s, v21.4s, v19.s[0]
        fmla v30.4s, v22.4s, v19.s[0]
        fmla v31.4s, v23.4s, v19.s[0]
        
        
        
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        add x0, x0, #16*4

        fmla v0.4s, v20.4s, v16.s[1]
        fmla v1.4s, v21.4s, v16.s[1]
        fmla v2.4s, v22.4s, v16.s[1]
        fmla v3.4s, v23.4s, v16.s[1]
        
        fmla v4.4s, v20.4s, v17.s[1]
        fmla v5.4s, v21.4s, v17.s[1]
        fmla v6.4s, v22.4s, v17.s[1]
        fmla v7.4s, v23.4s, v17.s[1]
        
        fmla v24.4s, v20.4s, v18.s[1]
        fmla v25.4s, v21.4s, v18.s[1]
        fmla v26.4s, v22.4s, v18.s[1]
        fmla v27.4s, v23.4s, v18.s[1]
        
        fmla v28.4s, v20.4s, v19.s[1]
        fmla v29.4s, v21.4s, v19.s[1]
        fmla v30.4s, v22.4s, v19.s[1]
        fmla v31.4s, v23.4s, v19.s[1]
        
        
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        add x0, x0, #16*4

        fmla v0.4s, v20.4s, v16.s[2]
        fmla v1.4s, v21.4s, v16.s[2]
        fmla v2.4s, v22.4s, v16.s[2]
        fmla v3.4s, v23.4s, v16.s[2]
        
        fmla v4.4s, v20.4s, v17.s[2]
        fmla v5.4s, v21.4s, v17.s[2]
        fmla v6.4s, v22.4s, v17.s[2]
        fmla v7.4s, v23.4s, v17.s[2]
        
        fmla v24.4s, v20.4s, v18.s[2]
        fmla v25.4s, v21.4s, v18.s[2]
        fmla v26.4s, v22.4s, v18.s[2]
        fmla v27.4s, v23.4s, v18.s[2]
        
        fmla v28.4s, v20.4s, v19.s[2]
        fmla v29.4s, v21.4s, v19.s[2]
        fmla v30.4s, v22.4s, v19.s[2]
        fmla v31.4s, v23.4s, v19.s[2]
        
        
        
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        
        fmla v0.4s, v20.4s, v16.s[3]
        fmla v1.4s, v21.4s, v16.s[3]
        fmla v2.4s, v22.4s, v16.s[3]
        fmla v3.4s, v23.4s, v16.s[3]
        
        fmla v4.4s, v20.4s, v17.s[3]
        fmla v5.4s, v21.4s, v17.s[3]
        fmla v6.4s, v22.4s, v17.s[3]
        fmla v7.4s, v23.4s, v17.s[3]
        
        fmla v24.4s, v20.4s, v18.s[3]
        fmla v25.4s, v21.4s, v18.s[3]
        fmla v26.4s, v22.4s, v18.s[3]
        fmla v27.4s, v23.4s, v18.s[3]
        
        fmla v28.4s, v20.4s, v19.s[3]
        fmla v29.4s, v21.4s, v19.s[3]
        fmla v30.4s, v22.4s, v19.s[3]
        fmla v31.4s, v23.4s, v19.s[3]
        
        //store matrix C
        
        st1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #16*4
        st1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #16*4
        st1 {v24.4s, v25.4s, v26.4s, v27.4s}, [x2]
        add x2, x2, #16*4
        st1 {v28.4s, v29.4s, v30.4s, v31.4s}, [x2]
        

        ret
        .size gemm_asm_asimd_32_32_32, (. - gemm_asm_asimd_32_32_32)
