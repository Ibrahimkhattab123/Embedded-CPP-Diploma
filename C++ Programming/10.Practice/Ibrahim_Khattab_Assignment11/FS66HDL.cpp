#include "FS66HDL.h"

void FS66HDL::Read_Data()
{
    std::cout << "Reading Data with FS66HDL" << std::endl;
}

void FS66HDL::Send_Data()
{
    std::cout << "Sending Data with FS66HDL" << std::endl;
}

std::unique_ptr<IFiberSensor> Make_FS66HDL()
{
    return std::make_unique<FS66HDL>();
}