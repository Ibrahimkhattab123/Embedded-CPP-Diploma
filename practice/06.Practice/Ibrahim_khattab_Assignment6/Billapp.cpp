#include "BILL.h"

int main ()
{
    WATER<long> water1(20000);
    std::cout << "water: " << water1.CalculateBill() << std::endl;
    GAS<long> gas1(20000);
    std::cout << "gas: " << gas1.CalculateBill() << std::endl;
    METALL<long> metall1(20000);
    std::cout << "metall: " << metall1.CalculateBill() << std::endl;
    std::vector<BILL<long>*> AllBillsLong;
    AllBillsLong.push_back(&water1);
    AllBillsLong.push_back(&gas1);
    AllBillsLong.push_back(&metall1);
    
    std::cout << "all bills " << Bill_For_All(AllBillsLong) << std::endl;

    std::cout << "..............." << std::endl;

    Clear_Bill_Vec(AllBillsLong);
    WATER<long> water2(10000);
    std::cout << "water: " << water2.CalculateBill() << std::endl;
    GAS<long> gas2(10000);
    std::cout << "gas: " << gas2.CalculateBill() << std::endl;
    METALL<long> metall2(10000);
    std::cout << "metall: " << metall2.CalculateBill() << std::endl;
    
    AllBillsLong.push_back(&water2);
    AllBillsLong.push_back(&gas2);
    AllBillsLong.push_back(&metall2);
    
    std::cout << "all bills " << Bill_For_All(AllBillsLong) << std::endl;


    std::cout << "..............." << std::endl;



    WATER<unsigned int> water3(150);
    std::cout << "water: " << water3.CalculateBill() << std::endl;
    GAS<unsigned int> gas3(150);
    std::cout << "gas: " << gas3.CalculateBill() << std::endl;
    METALL<unsigned int> metall3(150);
    std::cout << "metall: " << metall3.CalculateBill() << std::endl;
    std::vector<BILL<unsigned int>*> AllBillsint;
    AllBillsint.push_back(&water3);
    AllBillsint.push_back(&gas3);
    AllBillsint.push_back(&metall3);
    
    std::cout << "all bills " << Bill_For_All(AllBillsint) << std::endl;
    return 0;
}