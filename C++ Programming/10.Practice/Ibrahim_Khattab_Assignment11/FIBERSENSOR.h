#ifndef FIBER_SENSOR_H
#define FIBER_SENSOR_H

#include <iostream>
#include <memory>

class IFiberSensor
{

public:
   virtual void Read_Data() = 0;
   virtual void Send_Data() = 0;
   virtual ~IFiberSensor() = default;

};

std::unique_ptr<IFiberSensor> Make_FS66HDL();


#endif // FIBER_SENSOR_H