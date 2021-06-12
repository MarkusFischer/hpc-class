#include <iostream>
#include <cstdint>

extern "C" 
{
    void sve_example_0(uint32_t * in, uint32_t * out);
    void sve_example_2(uint32_t * in, uint32_t * out);
}

int main(int argc, char const * argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Run: " << argv[0] << " <0|2>" << std::endl;
        return 0;
    }
    int example = atoi(argv[1]);

    uint32_t dataIn[128] = {0};
    uint32_t dataOut[128] = {0};

    for (unsigned int i = 0; i < 128; ++i)
    {
        dataIn[i] = (i + 1) * 2;
    }

    if (example == 0) 
    {
        sve_example_0(dataIn, dataOut);
    }
    else if (example == 2)
    {
        sve_example_2(dataIn, dataOut);
    }
    for (unsigned int i = 0; i < 128; ++i)
    {
        std::cout << "i / in / out: " << i << " / " << dataIn[i] << " / " << dataOut[i] << std::endl;
    } 
}
