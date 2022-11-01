#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
namespace Company
{
    namespace component
    {

        class Employee
        {
        public:
            Employee();
            Employee(std::uint16_t ID,
                     std::uint32_t Salary,
                     std::string Name,
                     bool HiringStatus);
            void SetID(std::uint16_t LocalID);
            std::uint16_t GetID();
            void SetName(std::string FirstNameLocal, std::string LastNameLocal);
            std::string GetName();

        private:
            std::uint16_t mID;
            std::uint32_t mSalary;
            std::string mName;
            bool mHiringStatus;
        };
    }
}

#endif