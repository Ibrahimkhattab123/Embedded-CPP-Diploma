#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include <algorithm>

constexpr double HighCons = 300000;
constexpr double LowCons = 200000;
constexpr float HighFactor = 1.25;
constexpr int LowFactor = 2;
constexpr int OtherFactor = 5;

constexpr int GasFactor = 10;

constexpr int ElectricityFactor = 5;

// abstract template class, strateg interface
//The Strategy interface encapsulates the calculation variations and can be implemented by all algorithms simultaneously.

template <class T, class M>
class BILL
{
public:
    virtual float CalculateBill() = 0;
};

// derived template class, concrete strategy A
template <class T, class M>
class WATER : public BILL<T, M>
{
public:
    WATER(T consumption) : mConsumption(consumption) {}
    WATER() {}
    M CalculateBill() override
    {
        T retVal = 0;
        if (mConsumption >= HighCons)
        {
            retVal = mConsumption * HighFactor;
        }
        else if ((mConsumption >= LowCons) && (mConsumption < HighCons))
        {
            retVal = mConsumption * LowFactor;
        }
        else
        {
            retVal = mConsumption * OtherFactor;
        }
        return retVal;
    }

private:
    T mConsumption;
};

// derived template class, concrete strategy B
template <class T, class M>
class GAS : public BILL<T, M>
{
public:
    GAS(T consumption) : mConsumption(consumption) {}
    GAS() {}
    M CalculateBill() override
    {
        return mConsumption * GasFactor;
    }

private:
    T mConsumption;
};

// derived template class, concrete strategy C
template <class T, class M>
class Electricity : public BILL<T, M>
{
public:
    Electricity(T consumption) : mConsumption(consumption) {}
    Electricity() {}
    M CalculateBill() override
    {
        return mConsumption * ElectricityFactor;
    }

private:
    T mConsumption;
};

// context class
//For interacting with the Context, the generic interface represents just one way of triggering ConcreteStrategy algorithms.
template <class T, class M>
class CitizenBill
{
public:
    CitizenBill(BILL<T, M> *bill) : BillObj(bill)
    {
    }
    M CalculateBill()
    {
        return BillObj->CalculateBill();
    }

private:
    BILL<T, M> *BillObj;
};

template <class T, class M>
M Bill_For_All(std::vector<CitizenBill<T, M> *> BillVec)
{
    M retVal = 0;
    for (auto BillElem : BillVec)
    {
        retVal += BillElem->CalculateBill();
    }
    return retVal;
}

// Context method to reuse the same vector for all kind of bills
template <class T, class M>
void Clear_Bill_Vec(std::vector<CitizenBill<T, M> *> &BillVec)
{
    BillVec.clear();
}
#endif // BILL_H