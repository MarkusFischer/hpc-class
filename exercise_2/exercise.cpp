//
// Created by markus on 4/22/21.
//
#include <iostream>
#include <bitset>

unsigned int instruction_asimd_compute( unsigned int  i_vec_instr,
                                        unsigned char i_vec_reg_dst,
                                        unsigned char i_vec_reg_src_0,
                                        unsigned char i_vec_reg_src_1 );

int main()
{
    std::cout << "bit patterns" << std::endl << "#############" << std::endl;
    unsigned char l_data1  = 1;
    std::cout << "unsigned char l_data1  = 1: " << std::bitset<8>(l_data1) << std::endl;

    unsigned char l_data2  = 255;
    std::cout << "unsigned char l_data2  = 255: " << std::bitset<8>(l_data2) << std::endl;

    unsigned char l_data3  = l_data2 + 1;
    std::cout << "unsigned char l_data3 = l_data2 + 1:" << std::bitset<8>(l_data3) << std::endl;

    unsigned char l_data4  = 0xA1;
    std::cout << "unsigned char l_data4  = 0xA1: " << std::bitset<8>(l_data4) << std::endl;

    unsigned char l_data5  = 0b1001011;
    std::cout << "unsigned char l_data5  = 0b1001011: " << std::bitset<8>(l_data5) << std::endl;

    unsigned char l_data6  = 'H';
    std::cout << "unsigned char l_data6  = 'H': " << std::bitset<8>(l_data6) << std::endl;

    char l_data7  = -4;
    std::cout << "char l_data7  = -4: " << std::bitset<8>(l_data7) << std::endl;

    unsigned int  l_data8  = 1u << 11;
    std::cout << "unsigned int  l_data8  = 1u << 11: " << std::bitset<32>(l_data8) << std::endl;

    unsigned int  l_data9 = l_data8 << 21;
    std::cout << "unsigned int  l_data9 = l_data8 << 21: " << std::bitset<32>(l_data9) << std::endl;

    unsigned int  l_data10  = 0xFFFFFFFF >> 5;
    std::cout << "unsigned int  l_data10  = 0xFFFFFFFF >> 5: " << std::bitset<32>(l_data10) << std::endl;

    unsigned int  l_data11 = 0b1001 ^ 0b01111;
    std::cout << "unsigned int  l_data11 = 0b1001 ^ 0b01111: " << std::bitset<32>(l_data11) << std::endl;

    unsigned int  l_data12 = ~0b1001;
    std::cout << "unsigned int  l_data12 = ~0b1001: " << std::bitset<32>(l_data12) << std::endl;

    unsigned int  l_data13 = 0xF0 & 0b1010101;
    std::cout << "unsigned int  l_data13 = 0xF0 & 0b1010101: " << std::bitset<32>(l_data13) << std::endl;

    unsigned int  l_data14 = 0b001 | 0b101;
    std::cout << "unsigned int  l_data14 = 0b001 | 0b101: " << std::bitset<32>(l_data14) << std::endl;

    unsigned int  l_data15 = 7743;
    std::cout << "unsigned int  l_data15 = 7743: " << std::bitset<32>(l_data15) << std::endl;

    int  l_data16 = -7743;
    std::cout << "int  l_data16 = -7743: " << std::bitset<32>(l_data16) << std::endl;

    std::cout << "#############" << std::endl << std::endl;

    std::cout << "Testing instruction_asimd_compute:" << std::endl;
    std::cout << "Test case 1: ";

    unsigned int i_vec_instr = 0b01001110001000001100110000000000;
                             //0b01001110001000101100110000100000
    unsigned char i_vec_reg_dst = 0b00000000;
    unsigned char i_vec_reg_src_0 = 0b00000001;
    unsigned char i_vec_reg_src_1 = 0b00000010;
    unsigned int result = 0b01001110001000101100110000100000;

    if (instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1) == result)
        std::cout << "Success!" << std::endl;
    else
    {
        std::cout << "Failed!" << std::endl;
        std::cout << "expected:" << std::bitset<32>(result) << std::endl;
        std::cout << "received:" << std::bitset<32>(instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1)) << std::endl;
    }

    std::cout << "Test case 2: ";
    i_vec_instr = 0;
    i_vec_reg_dst = 0xFF;
    i_vec_reg_src_0 = 0xFF;
    i_vec_reg_src_1 = 0xFF;
    result = 0b00000000000111110000001111111111;
    if (instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1) == result)
        std::cout << "Success!" << std::endl;
    else
    {
        std::cout << "Failed!" << std::endl;
        std::cout << "expected:" << std::bitset<32>(result) << std::endl;
        std::cout << "received:" << std::bitset<32>(instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1)) << std::endl;
    }

    std::cout << "Test case 3: ";
    i_vec_instr = 0b01010101010101010101010101010101;
    i_vec_reg_dst = 0b00001010;
    i_vec_reg_src_0 = 0b00011111;
    i_vec_reg_src_1 = 0b00000000;
    result = 0b01010101010000000101011111101010;
    if (instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1) == result)
        std::cout << "Success!" << std::endl;
    else
    {
        std::cout << "Failed!" << std::endl;
        std::cout << "expected:" << std::bitset<32>(result) << std::endl;
        std::cout << "received:" << std::bitset<32>(instruction_asimd_compute(i_vec_instr, i_vec_reg_dst, i_vec_reg_src_0, i_vec_reg_src_1)) << std::endl;
    }


}

unsigned int instruction_asimd_compute( unsigned int  i_vec_instr,
                                        unsigned char i_vec_reg_dst,
                                        unsigned char i_vec_reg_src_0,
                                        unsigned char i_vec_reg_src_1 )
{
    //Idee erst mit Bitmaske entsprechende Elemente in i_vec_instr auf 0 setzen
    //dann oder mit entsprechenden parameter bits
    return (i_vec_instr & ~0x001F03FF) | (i_vec_reg_dst & 0x1F) //Bits 0-4 should be set to bits 0-4 of i_vec_reg_dst
                                      | ((static_cast<unsigned int>(i_vec_reg_src_0) & 0x1F) << 5) //Bits 5-9 should be set to bits 0-4 of i_vec_reg_src_0
                                      | ((static_cast<unsigned int>(i_vec_reg_src_1) & 0x1F) << 16); //Bits 16-20 should be set to bits 0-4 of i_vec_reg_src_1
}