#include <iostream>
#include "employee.h"

/* creat a class Employee wich has proberties
        id, FirstName, LastName, Salary, HiringStatus

       and behaviors
       SetID, GetID, SetFName, GetFName, SetSalary, Getsalary, SetHiringStatus, GetHiringStatus

*/

//to force an object to use the initialzed instructor 
//use the keyword "explicit" before the initialzed instructor and delete the construcor
//Explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++

int main()
{
    constexpr bool HIRED = true;
    Company::component::Employee EmployeeOne(1, 200, "Ibrahim Khattab", HIRED);
    Company::component::Employee EmployeeTwo; //default instructor
    EmployeeOne.SetID(12);
    std::cout << "Employee ID : " << EmployeeOne.GetID() << std::endl;
    std::cout << "Employee Name : " << EmployeeOne.GetName() << std::endl;
    std::cout << "***********************************" << std::endl;
    //if default contructor used then data must be set like this with set functions
    EmployeeTwo.SetID(20);
    EmployeeTwo.SetName("Adnan Islam", "Khattab"); 
    std::cout << "Employee ID : " << EmployeeTwo.GetID() << std::endl;
    std::cout << "Employee Name : " << EmployeeTwo.GetName() << std::endl;


    return 0;
}
