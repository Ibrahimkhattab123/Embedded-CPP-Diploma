#include <iostream>
 
 float GetMiles(){
     
     float mile;
    std:: cout << "please enter the distance in miles" << std::endl; 
    std::cin >> mile;
 return mile;
 }

float MilesToKilo(float mile){

 constexpr float MILE_TO_KILO = 1.6;
float kilometer = mile*MILE_TO_KILO;
return kilometer;
}

 int main (){
    //float mile;
    // constexpr float MILE_TO_KILO = 1.6; // in this way we do same as macros but in the compilation time 
    //and it does not take any space in the memory like macros 
    //in C++, it's better to not use macros, because macros doesn't define the type of it 
    //std:: cout << "please enter the distance in miles" << std::endl; 
    //std::cin >> mile;
    //float kilometer = mile*MILE_TO_KILO;  // don't use magic values/ magic numbers, solution: perprocessor in C, with cinstexpr in C++
    float mile = GetMiles();
    float kilometer = MilesToKilo(mile);
    std:: cout << "Distance in kilometers = "<< kilometer << std::endl;

   return 0;

 }