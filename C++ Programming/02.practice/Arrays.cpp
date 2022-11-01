#include <iostream>
#include <array>
#include <vector>
#include <string>

constexpr int LIST_INTS_SIZE = 5;
int main()
{
    std::array<int, LIST_INTS_SIZE> list_ints;
    std::array<int, LIST_INTS_SIZE> nums = {1,2,3,4,5};
    std::string str = "Ibrahim Khattab";

    std::array<int, LIST_INTS_SIZE>::iterator it;  //statically allocated, we should know the size of the array, we iterate over it
    
    std::vector<int>::iterator itv;                //dynamically allocated
    std::string::iterator itstr;                   //dynamically allocated

    for (it = nums.begin(); it != nums.end(); it++)
    {
        std::cout << "Element: " << *it << std::endl;
    }

    for ( int &element: list_ints)
    {
        std::cin >> element;

    }

    for (int &element : list_ints)
    {

        std::cout << "Element: " << element << std::endl;
    }



    return 0;
}