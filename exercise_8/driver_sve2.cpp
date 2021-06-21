#include <iostream>
#include <cstdint>

extern "C" 
{
    void fmlalb_example(float* const a, float* const b, float* c);
    void fmlalt_example(float* const a, float* const b, float* c); 
    void udot_example(float* const a, float* const b, float* c);
}


int main()
{
    float dataIn1[128] = {0};
    float dataIn2[128] = {0};
    float dataOut[128] = {0};

    for (unsigned int i = 0; i < 128; ++i)
    {
        dataIn1[i] = (i + 1) * 2;
        dataIn2[i] = (i + 1) * 3;
    }
    return 0;

    std::cout << "fmlalb kernel" << std::endl;
    fmlalb_example(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }


    std::cout << std::endl << std::endl << "fmlalt kernel" << std::endl;
    fmlalt_example(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }

    std::cout << std::endl << std::endl << "udot kernel" << std::endl;
    udot_example(dataIn1, dataIn2, dataOut);

    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in1 / in2 / out: " << i << " / " << dataIn1[i] << " / " << dataIn2[i] << " / " << dataOut[i] << std::endl;
    }
}