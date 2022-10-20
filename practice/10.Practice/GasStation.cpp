#include <iostream>
#include <memory>

class GasolineSource
{
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default;
};

class GasStation : public GasolineSource
{
public:
    virtual void FuelUp()
    {
        std::cout << "Pumping gas at gas station" << std::endl;
    }
};

class FuelCan : public GasolineSource
{
public:
    virtual void FuelUp()
    {
        std::cout << "Pumping gas from fuel can" << std::endl;
    }
};

class Car
{

private:
    std::shared_ptr<GasolineSource> gasolineService = nullptr;

public:
    // dependency injection
    //  The dependency for a source of gasoline is passed in
    //  through constructor injection
    //  as opposed to hard-coded into the class definition.
    Car(std::shared_ptr<GasolineSource> service)
        : gasolineService(service)
    {
        // If the dependency was not defined, throw an exception.
        if (gasolineService == nullptr)
        {
            throw std::invalid_argument("service must not be null");
        }
    }
    void getGasoline()
    {
        std::cout << "Car needs more gasoline!" << std::endl;
        // Abstract away the dependency implementation with polymorphism.
        gasolineService->FuelUp();
    }
};

int main()
{
    std::shared_ptr<GasolineSource> stationService = std::make_shared<GasStation>();
    std::shared_ptr<GasolineSource> canService = std::make_shared<FuelCan>();

    Car Car1(stationService);
    Car1.getGasoline();

    std::cout << std::endl;

    Car duneBuggy(canService);
    duneBuggy.getGasoline();

    return 0;
}