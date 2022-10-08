#include "BILL.h"

//Refactoring the code from 06.Practice to have the strategy pattern

int main ()
{
    //three object for bills
    WATER<long,float>       water1(20000);            
    GAS<long,float>         gas1(20000);              
    Electricity<long,float> electricity1(20000);     

    //interchangeable methids over the context CitizenBill
    CitizenBill<long, float> WaterBill1(&water1);
    CitizenBill<long, float> GasBill1(&gas1);
    CitizenBill<long, float> ElectricityBill1(&electricity1);

    //method to calculate the summ of all bills, wich has a context class 
    //in thuis way, when we want to change something 
    //we change it in the object class 
    //but we don't have to change any thing in the context class and so in the app code
    std::vector<CitizenBill<long,float>*> AllBillsLong;
    

    AllBillsLong.push_back(&WaterBill1);
    AllBillsLong.push_back(&GasBill1);
    AllBillsLong.push_back(&ElectricityBill1);
    
    std::cout << "all bills " << Bill_For_All(AllBillsLong) << std::endl;
    Clear_Bill_Vec(AllBillsLong);

    std::cout << "..............." << std::endl;

    WATER<unsigned int,float>       water2(150);
    GAS<unsigned int,float>         gas2(150);
    Electricity<unsigned int,float> electricity2(150);
    
    
    CitizenBill<unsigned int, float> WaterBill2(&water2);
    CitizenBill<unsigned int, float> GasBill2(&gas2);
    CitizenBill<unsigned int, float> ElectricityBill2(&electricity2);


    std::vector<CitizenBill<unsigned int,float>*> AllBillsint;

    AllBillsint.push_back(&WaterBill2);
    AllBillsint.push_back(&GasBill2);
    AllBillsint.push_back(&ElectricityBill2);
    
    std::cout << "all bills " << Bill_For_All(AllBillsint) << std::endl;
    Clear_Bill_Vec(AllBillsint);

    std::cout << "..............." << std::endl;

    return 0;
}