#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

namespace University
{
    namespace Department
    {
        class Student
        {
        private:
        std::string S_Name;
        std::string S_Department;
        std::string S_GraduateExpect;
        std::uint16_t S_ID;
        std::uint16_t S_Age;
        std::uint8_t S_Sex;
           
        public:
        Student();
        Student(std::string S_Name,
                std::string S_Department,
                std::string S_GraduateExpect,
                std::uint16_t S_ID,
                std::uint16_t S_Age,
                std::uint8_t S_Sex);
        

        ~Student();
        /*Accessors (Getters) and Mofifiers (Setters)*/

        void Set_S_Name(const std::string Local_S_Name);
        const std::string& Get_S_Name(void) const;

        void Set_S_Department(const std::string Local_S_Department);
        const std::string& Get_S_Departmant(void) const;

        void Set_S_GraduateExpect(const std::string Local_S_GraduateExpect);
        const std::string& Get_S_GraduateExpect(void) const;

        void Set_S_ID(const std::uint16_t Local_S_ID);
        const std::uint16_t& Get_S_ID(void) const;

        void Set_S_Age(const std::uint16_t Local_S_Age);
        const std::uint16_t& Get_S_Age(void) const;

        void Set_S_Sex(const std::uint8_t Local_S_Sex);
        const std::uint8_t& Get_S_Sex(void) const;
        
        /*Methods*/
        void Print_Steudent_Data(void);
        };
        
        
        
        
        
        

    }
}

#endif