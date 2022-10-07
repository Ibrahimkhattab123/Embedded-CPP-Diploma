#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 5> Nums{24,5,34,21,5};
    int x = 5;
    constexpr int bd= 10;

    std::for_each(Nums.begin(), Nums.end(), [&,bd](int &element) -> int
    {
        
        if (element > bd)
        {
            
            return (element += 2);
        }
        else
        {
            return (element *= 2);
        }
        
    });

    std::sort(Nums.begin(), Nums.end(), [](int &a, int &b) -> bool
    {
        return a > b;


    });

    for (int element : Nums)
    {
        std::cout<< element << std::endl;
    }

    return 0;
}