#include <iostream>
#include <cstdint>

extern "C" 
{
    void fmlalb(float* const a, float* const b, float* c);
    void fmlalt(float* const a, float* const b, float* c); 
    void udot(float* const a, float* const b, float* c);
}


int main()
{
    uint32_t dataIn1[128] = {0};
    uint32_t dataIn2[128] = {0};
    uint32_t dataOut[128] = {0};

    for (unsigned int i = 0; i < 128; ++i)
    {
        dataIn1[i] = (i + 1) * 2;
        dataIn2[i] = (i + 1) * 3;
    }
    return 0;

    std::cout << "fmlalb kernel" << std::endl;
    fmlalb(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }


    std::cout << std::endl << std::endl << "fmlalt kernel" << std::endl;
    fmlalt(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }

    std::cout << std::endl << std::endl << "udot kernel" << std::endl;
    udot(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }
}