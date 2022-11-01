#include <iostream>
#include "student.h"

/* 
Write a class student that has 3 properties and 6 methods for setters and getters 
and a constructor that takes parameters and initializes the member variables i.e
m_id
m_age
m_name

 Student(std::string S_Name,
                std::string S_Department,
                std::string S_GraduateExpect,
                std::uint16_t S_ID,
                std::uint8_t S_Age,
                std::uint8_t S_Sex); 
*/

int main()
{
    University::Department::Student StudentOne("Ibrahim Khattab", "EE-IT", "SS2024", 18017, 20, 'M');

    std::cout << "StudentOne Name: " << StudentOne.Get_S_Name() << std::endl;
    std::cout << "StudentOne Department: " << StudentOne.Get_S_Departmant() << std::endl;
    std::cout << "StudentOne graduate expectation year: " << StudentOne.Get_S_GraduateExpect() << std::endl;
    std::cout << "StudentOne ID-Number: " << StudentOne.Get_S_ID() << std::endl;
    std::cout << "StudentOne Age: " << StudentOne.Get_S_Age() << std::endl;
    std::cout << "StudentOne Sex: " << StudentOne.Get_S_Sex() << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "Data from methods  : " << std::endl;
    StudentOne.Print_Steudent_Data();

    University::Department::Student StudentTwo;
    StudentTwo.Set_S_Name("Adnan Islam Khattab");
    StudentTwo.Set_S_Department("CS");
    StudentTwo.Set_S_GraduateExpect("SS2032");
    StudentTwo.Set_S_ID(3022);
    StudentTwo.Set_S_Age(22);
    StudentTwo.Set_S_Sex('M');

    std::cout << "StudentTwo Name: " << StudentTwo.Get_S_Name() << std::endl;
    std::cout << "StudentTwo Department: " << StudentTwo.Get_S_Departmant() << std::endl;
    std::cout << "StudentTwo graduate expectation year: " << StudentTwo.Get_S_GraduateExpect() << std::endl;
    std::cout << "StudentTwo ID-Number: " << StudentTwo.Get_S_ID() << std::endl;
    std::cout << "StudentTwo Age: " << StudentTwo.Get_S_Age() << std::endl;
    std::cout << "StudentTwo Sex: " << StudentTwo.Get_S_Sex() << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "Data from methods  : " << std::endl;
    StudentTwo.Print_Steudent_Data();

    /*Destructor will be excecuted here (statically deallocation) (LIFO)
    Destructor can be very useful for releasing resources before coming out of the program like closing files,
     releasing memories etc.
     It will work like this: 
     
     Destructor called for: Adnan Islam Khattab
     Destructor called for: Ibrahim Khattab
     */

    return 0;
}