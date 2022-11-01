#include "employee.h"



            Company::component::Employee::Employee() //default constuctor
            {


            }
            Company::component::Employee::Employee(std::uint16_t ID,
                     std::uint32_t Salary,
                     std::string Name, // this is initializer list
                     bool HiringStatus): mID(ID), mSalary(Salary), mName(Name), mHiringStatus(HiringStatus)
            {
                std::cout << "Employee ID : "       << mID
                          << " ,Employee Salary : " << mSalary
                          << " ,Employee Name : "   << mName
                          << " ,Employee Status : " << mHiringStatus << std::endl;
            }
            void  Company::component::Employee::SetID(std::uint16_t LocalID)
            {
                this->mID = LocalID;
            }
            std::uint16_t  Company::component::Employee::GetID()
            {
                return this->mID;
            }
            void  Company::component::Employee::SetName(std::string FirstNameLocal, std::string LastNameLocal)
            {
                this -> mName = FirstNameLocal + " " + LastNameLocal;
                
            }
            std::string  Company::component::Employee::GetName()
            {
                return this ->  mName;
            }



