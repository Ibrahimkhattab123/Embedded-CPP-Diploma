#include <iostream>
#include <set>
#include <unordered_set>

int main ()
{
    std::set<int> Set1 = {1,10,3,5,20};

    std::cout << "Numbers in Set: ";
    for (auto Element : Set1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::multiset<int> Set2 = {1,10,3,5,20, 10};
    std::cout << "Numbers in multi set: ";
    for (auto Element : Set2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::unordered_multiset<int> Set3 = {1,10,3,5,20, 10};
    std::cout << "Numbers in unordered multi set: ";
    for (auto Element : Set3)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;


    return 0;
}