//First task


//Student grading system
//ask student for their grade
//evaluate grade : 
// if grade is less than 50 then they are failed
// if grade is greater than 50 and less than  65 then they are passed
// if grade is greater than 65 and less than 75 then they are Good
// if grade is greater than 75 and less than 85 then they are very Good
// if grade is greater than 85 to 100 then they are Excellent
//print results

#include <iostream>
#include "grade.h"
using namespace GRADE_EVALUATION;



//namespace is a defined scope of code or entities (Variables and methods) 
//otherwise entities are global
//namespaces provides the space wher to declare and define identifiers i.e. variables, methods or classes
//Multiple namespace blocks with the same name are allowed
//This allows organizing the elements of programs into different logical scopes referred to by names.
//only global, can be nested, no access specifiers (private, public)
//namespace aliasing in c++ like namespace alias = name1::name2::name3;
//Methodes can be seprately used from a namespace or they can be combined together in other Method (like RunGradeEvaluation())



 
int main()
{
    RunGradeEvaluation();    //or GRADE_EVALUATION::RunGradeEvaluation(); with using namespace command
   


    return 0;
}