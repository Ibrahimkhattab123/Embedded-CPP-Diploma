#include "CURRENTCOLLECTOR.h"
#include "FS66HDL.h"



int main ()
{   std::unique_ptr<IFiberSensor> Sensor1 = Make_FS66HDL();
    CurrentCollector Pantograph(std::make_unique<FS66HDL>());
    //CurrentCollector Pantograph(std::move(Sensor1));
    Pantograph.Reading();
    Pantograph.Writing();

    return 0;
}