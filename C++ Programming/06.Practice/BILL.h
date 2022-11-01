#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include <algorithm>

template <class T, class M>
class BILL
{
    public:
    virtual float CalculateBill() = 0;
    private:
    T mConsumption;
};

template <class T, class M>
class WATER : public BILL<T,M>
{
    public:
    WATER(T consumption): mConsumption(consumption){}
    WATER(){}
    M CalculateBill() override
    {
        T retVal = 0;
        if (mConsumption >= 300000)
        {
            retVal = mConsumption * 1,25;
        }
        else if ((mConsumption >= 200000) && (mConsumption < 300000))
        {
            retVal = mConsumption * 2;
        }
        else
        {
            retVal = mConsumption * 5;
        }
        return retVal;
    }
    private:
    T mConsumption;
};
template <class T, class M>
class GAS : public BILL<T,M>
{
    public:
   GAS(T consumption): mConsumption(consumption){}
   GAS(){}
    M CalculateBill() override
    {
        return mConsumption * 10;
    }
    private:
    T mConsumption;
};
template <class T, class M>
class METALL : public BILL<T,M>
{
    public:
   METALL(T consumption): mConsumption(consumption){}
   METALL(){}
    M CalculateBill() override
    {
        return mConsumption * 5;
    }
    private:
    T mConsumption;
};
template <class T, class M>
M Bill_For_All (std::vector <BILL<T,M> *> BillVec)
{
    M retVal = 0;
    for (auto BillElem: BillVec)
    {
        retVal += BillElem -> CalculateBill();
    }
    return retVal;
    
}
//to reuse the same vector for all kind of bills
template <class T, class M>
void Clear_Bill_Vec (std::vector <BILL<T,M> *> &BillVec)
{
   BillVec.clear();
    
}
#endif //BILL_H