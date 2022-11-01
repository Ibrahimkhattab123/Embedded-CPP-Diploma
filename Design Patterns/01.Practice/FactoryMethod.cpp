#include <iostream>
#include <memory>

enum VehicleType
{
    VehicleType_TwoWheeler,
    VehicleType_ThreeWheeler,
    VehicleType_FourWheeler
};

class Vehicle
{
public:
    virtual void Print_Vehicle() = 0;
    static std::shared_ptr<Vehicle> Create(VehicleType VType);
};

class TwoWheeler : public Vehicle
{
public:
    void Print_Vehicle() override
    {
        std::cout << "Two wheeler vehicle" << std::endl;
    }
};

class ThreeWheeler : public Vehicle
{
public:
    void Print_Vehicle() override
    {
        std::cout << "Three wheeler vehicle" << std::endl;
    }
};
class FourWheeler : public Vehicle
{
public:
    void Print_Vehicle() override
    {
        std::cout << "Foue wheeler vehicle" << std::endl;
    }
};

// Factory method

std::shared_ptr<Vehicle> Vehicle::Create(VehicleType VType)
{

    if (VType == VehicleType_TwoWheeler)
    {
        return std::make_shared<TwoWheeler>();
    }
    else if (VType == VehicleType_ThreeWheeler)
    {
        return std::make_shared<ThreeWheeler>();
    }
    else if (VType == VehicleType_FourWheeler)
    {
        return std::make_shared<FourWheeler>();
    }
    else
    {
        return nullptr;
    }
}

class Client
{
public:
    Client(VehicleType _VType) : VType(_VType)
    {
        UPtrVehicle = Vehicle::Create(VType);
    }
    ~Client() {}
     std::shared_ptr<Vehicle>& Get_Vehicle() 
     {
        return UPtrVehicle;
     }

private:
    std::shared_ptr<Vehicle> UPtrVehicle;
    VehicleType VType;
};

int main()
{
    Client *pClient = new Client(VehicleType_TwoWheeler);
    auto pVehicle = pClient->Get_Vehicle();
    pVehicle->Print_Vehicle();
    delete pClient;
   
    return 0;
}