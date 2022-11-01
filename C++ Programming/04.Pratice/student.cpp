#include "student.h"
University::Department::Student::Student()
{

}
University::Department::Student::Student(std::string Name,
                                        std::string Department,
                                        std::string GraduateExpect,
                                        std::uint16_t ID,
                                        std::uint16_t Age,
                                        std::uint8_t Sex)
                                        : S_Name(Name), S_Department(Department),
                                          S_GraduateExpect(GraduateExpect),
                                          S_ID(ID), S_Age(Age), S_Sex(Sex)
{

}
/*Destructor can not take any return value nor parameter*/
University::Department::Student::~Student(){
    std::cout << "Destructor called for: " << this -> S_Name <<  std::endl; 
}  
/*
first const: returns const data to the object proberties, hence it cann't be changed outside the function
&: returns an alias (not a copy) to the object proberties, 
second const: we won't change the data we get, hence the get function doesn't change any variable 
inline qualifier: read it in one line (did not work, why?)
*/    
/*S_Name*/
void University::Department::Student::Set_S_Name(const std::string Local_S_Name)
{
    this -> S_Name = Local_S_Name;
}
const std::string& University::Department::Student::Get_S_Name(void) const
{
    return this -> S_Name;
}
/*S_Department*/
void  University::Department::Student::Set_S_Department(const std::string Local_S_Department)
{
    this -> S_Department = Local_S_Department;
}
const std::string&  University::Department::Student::Get_S_Departmant(void) const 
{
    return this -> S_Department;
}
/*S_GraduateExpect*/
void  University::Department::Student::Set_S_GraduateExpect(const std::string Local_S_GraduateExpect)
{
    this -> S_GraduateExpect= Local_S_GraduateExpect;
}
const std::string&  University::Department::Student::Get_S_GraduateExpect(void) const 
{
    return this -> S_GraduateExpect;
}
/*S_ID*/
void  University::Department::Student::Set_S_ID(const std::uint16_t Local_S_ID)
{
    this -> S_ID = Local_S_ID;
}
const std::uint16_t&  University::Department::Student::Get_S_ID(void) const 
{
    return this -> S_ID;
}
/*S_Age*/
void  University::Department::Student::Set_S_Age(const std::uint16_t Local_S_Age)
{
    this -> S_Age = Local_S_Age;
}
const std::uint16_t&  University::Department::Student::Get_S_Age(void) const 
{
    return this -> S_Age;
}
/*S_Sex*/
void University::Department::Student::Set_S_Sex(const std::uint8_t Local_S_Sex)
{
    this -> S_Sex = Local_S_Sex;
}
const std::uint8_t& University::Department::Student::Get_S_Sex(void) const 
{
    return this -> S_Sex;
}
/*Methods*/
void University::Department::Student::Print_Steudent_Data(void)
{
    std::cout << "Student Name: " << this -> S_Name << std::endl;
    std::cout << "Student Department: " << this -> S_Department << std::endl;
    std::cout << "Student graduate expectation year: " << this -> S_GraduateExpect << std::endl;
    std::cout << "Student ID-Number: " << this -> S_ID << std::endl;
    std::cout << "Student Age: " << this -> S_Age << std::endl;
    std::cout << "Student Sex: " << this -> S_Sex << std::endl;
}