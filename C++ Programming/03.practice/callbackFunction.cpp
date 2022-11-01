#include <iostream>
#include <array>
#include <functional>

void Calculate(std::array<int, 5> arr, std::function<void (int&)> square, std::function<void (int&)> cube)
{
    for (auto num : arr)
    {
        if (num % 2 == 0)
        {
            square(num);
        }
        else
        {
            cube(num);
        }


    }

}

int main()
{
    std::array<int, 5> PasstoFun ={1,2,3,4,5};

    auto square = [](int &num) -> void {
        std::cout << "the sqaure of num " << num << " = " << num*num << std::endl; 
    };
    auto cube = [](int &num) -> void {
        std::cout << "the cube of num " << num << " = " << num*num*num << std::endl; 
    };

    Calculate(PasstoFun, square,cube);
    return 0;
}