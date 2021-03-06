        .text
        .type gemm_asm_asimd_19_4_4, %function
        .global gemm_asm_asimd_19_4_4
        /*
         * Performs the matrix-multiplication C+=A*B
         * with the shapes (19x4) = (19x4) * (4x4).
         * The input-data is of type float.
         *
         * @param x0 pointer to A.
         * @param x1 pointer to B.
         * @param x2 pointer to C.
         */ 
gemm_asm_asimd_19_4_4:
        
        //loading (upper part) matrix C
        ld1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #19*4
        ld1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #19*4
        ld1 {v24.4s, v25.4s, v26.4s, v27.4s}, [x2]
        add x2, x2, #19*4
        ld1 {v28.4s, v29.4s, v30.4s, v31.4s}, [x2]
        sub x2, x2, #3*19*4
        
        //loading matrix B
        ld1 {v16.4s, v17.4s, v18.4s, v19.4s}, [x1]
        
        //loading first row of A
        ld1 {v20.4s, v21.4s, v22.4s, v23.4s}, [x0]
        add x0, x0, #19*4

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
        add x0, x0, #19*4

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
        add x0, x0, #19*4

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
        sub x0, x0, #3*19*4-16*4
        
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
        
        //store (upper part) of matrix C
        
        st1 {v0.4s, v1.4s, v2.4s, v3.4s}, [x2]
        add x2, x2, #19*4
        st1 {v4.4s, v5.4s, v6.4s, v7.4s}, [x2]
        add x2, x2, #19*4
        st1 {v24.4s, v25.4s, v26.4s, v27.4s}, [x2]
        add x2, x2, #19*4
        st1 {v28.4s, v29.4s, v30.4s, v31.4s}, [x2]
        sub x2, x2, #3*19*4-16*4

        // loading lower part of matrix C
        ldr d0, [x2], #2*4
        ldr s1, [x2], #17*4

        ldr d2, [x2], #2*4
        ldr s3, [x2], #17*4

        ldr d4, [x2], #2*4
        ldr s5, [x2], #17*4

        ldr d6, [x2], #2*4
        ldr s7, [x2]
        sub x2, x2, #3*19*4 + 2*4

        //loading A
        ldr d20, [x0], #2*4
        ldr s21, [x0], #17*4

        ldr d22, [x0], #2*4
        ldr s23, [x0], #17*4

        ldr d24, [x0], #2*4
        ldr s25, [x0], #17*4

        ldr d26, [x0], #2*4
        ldr s27, [x0], #17*4


        //fmlas

        fmla v0.2s, v20.2s, v16.s[0]
        fmla s1, s21, v16.s[0]

        fmla v2.2s, v20.2s, v17.s[0]
        fmla s3, s21, v17.s[0]

        fmla v4.2s, v20.2s, v18.s[0]
        fmla s5, s21, v18.s[0]

        fmla v6.2s, v20.2s, v19.s[0]
        fmla s7, s21, v19.s[0]

       
        fmla v0.2s, v22.2s, v16.s[1]
        fmla s1, s23, v16.s[1]

        fmla v2.2s, v22.2s, v17.s[1]
        fmla s3, s23, v17.s[1]

        fmla v4.2s, v22.2s, v18.s[1]
        fmla s5, s23, v18.s[1]

        fmla v6.2s, v22.2s, v19.s[1]
        fmla s7, s23, v19.s[1]

       
        fmla v0.2s, v24.2s, v16.s[2]
        fmla s1, s25, v16.s[2]

        fmla v2.2s, v24.2s, v17.s[2]
        fmla s3, s25, v17.s[2]

        fmla v4.2s, v24.2s, v18.s[2]
        fmla s5, s25, v18.s[2]

        fmla v6.2s, v24.2s, v19.s[2]
        fmla s7, s25, v19.s[2]


        fmla v0.2s, v26.2s, v16.s[3]
        fmla s1, s27, v16.s[3]

        fmla v2.2s, v26.2s, v17.s[3]
        fmla s3, s27, v17.s[3]

        fmla v4.2s, v26.2s, v18.s[3]
        fmla s5, s27, v18.s[3]

        fmla v6.2s, v26.2s, v19.s[3]
        fmla s7, s27, v19.s[3]



        //store lower part of matrix C
        str d0, [x2], #2*4
        str s1, [x2], #17*4

        str d2, [x2], #2*4
        str s3, [x2], #17*4

        str d4, [x2], #2*4
        str s5, [x2], #17*4

        str d6, [x2], #2*4
        str s7, [x2]

        
        ret
        .size gemm_asm_asimd_19_4_4, (. - gemm_asm_asimd_19_4_4)
