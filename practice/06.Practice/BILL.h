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

template <class T>
class WATER : public BILL<T>
{
    public:
    WATER(T consumption): mConsumption(consumption){}
    WATER(){}
    float CalculateBill() override
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
template <class T>
class GAS : public BILL<T>
{
    public:
   GAS(T consumption): mConsumption(consumption){}
   GAS(){}
    float CalculateBill() override
    {
        return mConsumption * 10;
    }
    private:
    T mConsumption;
};
template <class T>
class METALL : public BILL<T>
{
    public:
   METALL(T consumption): mConsumption(consumption){}
   METALL(){}
    float CalculateBill() override
    {
        return mConsumption * 5;
    }
    private:
    T mConsumption;
};
template <class T>
float Bill_For_All (std::vector <BILL<T> *> BillVec)
{
    float retVal = 0;
    for (auto BillElem: BillVec)
    {
        retVal += BillElem -> CalculateBill();
    }
    return retVal;
    
}
//to reuse the same vector for all kind of bills
template <class T>
void Clear_Bill_Vec (std::vector <BILL<T> *> &BillVec)
{
   BillVec.clear();
    
}
#endif //BILL_H