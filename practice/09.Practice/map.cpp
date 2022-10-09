#include <iostream>
#include <map>

int main ()
{
    std::map<int, float> Map1;

    Map1.insert(std::pair<int, int>(1, 97.00));
    Map1.insert(std::pair<int, int>(2, 73.00));
    Map1.insert(std::pair<int, int>(3, 88.75));
    Map1.insert(std::pair<int, int>(4, 50.00));
    Map1.insert(std::pair<int, int>(5, 89.12));
    Map1.insert(std::pair<int, int>(6, 99.99));
    Map1.insert(std::pair<int, int>(7, 70.00));
    std::cout << "Numbers in map: ";
    for (auto Element : Set1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;



    return 0;
}