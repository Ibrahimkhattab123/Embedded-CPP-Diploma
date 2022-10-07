#include <iostream>

//Straategy Pattern is a bahavior pattern to change the algorithm dependent on the object
//Coponents are: 1) an abstract class (Inteface) which represents various strategies (Object)
//               2) Objects which have the real imolementation of the stratrgies
//               3) a context class which is responsable of changing the algorithm by giving a specific object 
              
               

//abstract
struct CarsSpeed
{
    virtual void CalculateSpeed() = 0;
};

struct BMW : CarsSpeed
{
    void CalculateSpeed() override
    {
        std::cout << "Calculating BMW speed" << std::endl;
    }
};

struct  MiniCooper : CarsSpeed
{
    void CalculateSpeed() override
    {
        std::cout << "Calculating MiniCooper speed" << std::endl;
    }

};

//Context
struct  Vehicle
{
    Vehicle(CarsSpeed *strategy) : StrategyObj(strategy)
    {

    }
    void CalculateSpeed() 
    {
        this->StrategyObj->CalculateSpeed();
    }

    //Aggregation
    CarsSpeed *StrategyObj;
};




int main ()
{
    BMW bmw;
    MiniCooper miniCooper;
    Vehicle BMW_I7(&bmw);
    Vehicle MiniCabrio(&miniCooper);
    BMW_I7.CalculateSpeed();
    MiniCabrio.CalculateSpeed();

    return 0;
}