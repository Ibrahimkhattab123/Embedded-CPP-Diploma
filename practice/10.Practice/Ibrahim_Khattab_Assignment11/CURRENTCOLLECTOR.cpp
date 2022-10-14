#include "CURRENTCOLLECTOR.h"

void CurrentCollector::Reading()
{
    this->FiberSensor->Read_Data();
}
void CurrentCollector::Writing()
{
    this->FiberSensor->Send_Data();
}
