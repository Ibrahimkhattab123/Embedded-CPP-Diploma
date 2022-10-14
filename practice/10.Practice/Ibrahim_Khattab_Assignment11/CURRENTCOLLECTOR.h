#ifndef CURRENT_COLLECTOR_H
#define CURRENT_COLLECTOR_H

#include "FIBERSENSOR.h"

class CurrentCollector
{
public:
    CurrentCollector(std::unique_ptr<IFiberSensor>&& _FiberSensor) 
                        : FiberSensor(std::move(_FiberSensor))
    {
    }
    void Reading();
    void Writing();
private:
    std::unique_ptr<IFiberSensor> FiberSensor;
};



#endif // CURRENT_COLLECTOR_H