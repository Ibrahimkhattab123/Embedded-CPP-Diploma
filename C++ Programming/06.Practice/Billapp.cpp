#include "BILL.h"

int main ()
{
    WATER<long,float> water1(20000);
    std::cout << "water: " << water1.CalculateBill() << std::endl;
    GAS<long,float> gas1(20000);
    std::cout << "gas: " << gas1.CalculateBill() << std::endl;
    METALL<long,float> metall1(20000);
    std::cout << "metall: " << metall1.CalculateBill() << std::endl;
    std::vector<BILL<long,float>*> AllBillsLong;
    AllBillsLong.push_back(&water1);
    AllBillsLong.push_back(&gas1);
    AllBillsLong.push_back(&metall1);
    
    std::cout << "all bills " << Bill_For_All(AllBillsLong) << std::endl;

    std::cout << "..............." << std::endl;

    Clear_Bill_Vec(AllBillsLong);
    WATER<long,float> water2(10000);
    std::cout << "water: " << water2.CalculateBill() << std::endl;
    GAS<long,float> gas2(10000);
    std::cout << "gas: " << gas2.CalculateBill() << std::endl;
    METALL<long,float> metall2(10000);
    std::cout << "metall: " << metall2.CalculateBill() << std::endl;
    
    AllBillsLong.push_back(&water2);
    AllBillsLong.push_back(&gas2);
    AllBillsLong.push_back(&metall2);
    
    std::cout << "all bills " << Bill_For_All(AllBillsLong) << std::endl;


    std::cout << "..............." << std::endl;



    WATER<unsigned int,float> water3(150);
    std::cout << "water: " << water3.CalculateBill() << std::endl;
    GAS<unsigned int,float> gas3(150);
    std::cout << "gas: " << gas3.CalculateBill() << std::endl;
    METALL<unsigned int,float> metall3(150);
    std::cout << "metall: " << metall3.CalculateBill() << std::endl;
    std::vector<BILL<unsigned int,float>*> AllBillsint;
    AllBillsint.push_back(&water3);
    AllBillsint.push_back(&gas3);
    AllBillsint.push_back(&metall3);
    
    std::cout << "all bills " << Bill_For_All(AllBillsint) << std::endl;
    return 0;
}