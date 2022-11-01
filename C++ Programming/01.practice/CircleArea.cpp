#include <iostream>

typedef double CircleRadius;
typedef double CircleArea;

int main (){

    constexpr float PI = 3.14;
    CircleRadius circleRadius; //it's better in C++ to define/declare the variables where we use them
    std::cout << "please enter the circle radius " << std::endl;
    std::cin >> circleRadius;
    CircleArea area = circleRadius * circleRadius * PI;
    std::cout << "circle area = " << area << std::endl;



    return 0;
}