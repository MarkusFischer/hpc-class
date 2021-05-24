# A New World


# GDB and Valgrind

## Assembly code explanation 

The assembly code does the following job: 
First it increments the value of the address in register x0 by 8 Byte and loads the value into register x1. 
After this it loads the value of address x0 + 8 in register x2 and the value of address x0 + 8 + 8 in register x3 (where +8 stands for +8 Bytes).
Finally the values of address x0 + 8 + 16 are stored in register x4 and from address x0 + 8 + 16 + 8 in register x5.

When used with the function call load_asm(l_a + 2) the address of l_a + 2 * sizeof(uint64_t*) is saved in register x0. Since our Neoverse N1 has a 64 bit architecture the size of a pointer is 8 Byte and therefore the address of the third element (value 300) is saved in register x0. 
Executing the three statements give us the follwing values for registers x1 to x5

x1 = 400
x2 = 400
x3 = 500
x4 = 600
x5 = 700

## running GDB

The values for our 5 registers after executing load_asm step by step
x0             0x432ec8            4402888
x1             0x190               400
x2             0x190               400
x3             0x1f4               500
x4             0x258               600
x5             0x2bc               700

## valgrind

Running lines 18, 21, and 24 is problematic because we read data outside of our allocated memory. 
The function call in line 18 makes problems from the beginning because we start to read data 4 * 8 bytes after the last element of l_a. 

The call in line 21 starts fine and reads the last value of l_a into registers x1 and x2, however the second load of the ldp is problematic again (since it exceeds the boundaries of the allocated space). 

The call in line 24 works fine until the last load operation of ldp. 

# Copying data

The written and generated files can be found in the repository. 
We can observe two things:

(1) the compiler does not unroll loops and produces therefore an overhead for incrementing and comparing the loop counter and jumps
(2) the generated code manipulates the address registers in extra steps and it loads only one value and not pairs. The reason behind this is probably the added flexibility through the loop. 

As far as I can see there is nearly no difference between the generated and disassembled variant of our copy_c function. Maybe optimization flags would make a difference in terms of loop unrolling. 
