#ifndef FS66HDL_H
#define FS66HDL_H

#include "FIBERSENSOR.h"

class FS66HDL : public IFiberSensor
{
public:
    void Read_Data() override;
    void Send_Data() override;
};


#endif // FS66HDL_H