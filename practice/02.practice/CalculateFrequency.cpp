#include <iostream>
#include <array>

namespace CALCULATE_FREQUENCY
{
    /******Config frequency calculation *****/
    constexpr int ArrSize = 13;
    std::array<int, ArrSize> arr = {3, 3, 5, 8, 9, 8, 9, 10, 17, 10, 11, 17, 10};
    std::array<int, ArrSize>::iterator it1;
    std::array<int, ArrSize>::iterator it3;
    std::array<int, ArrSize>::iterator it2;
    std::uint16_t count = 0;
    /******Enter an array with a size of 13 *****/
    void WelecmeArray(void)
    {
        std::cout << "please enter 13 integer numbers:" << std::endl;
        for (int &it : arr)
        {
            std::cin >> it;
        }
    }
    /******calculate the frequency of numbers in an array *****/
    void CalculateFrequency(void)
    {
        /******iterate over all elements with a pointer at the beginning of the array *****/
        for (it1 = arr.begin(); it1 != arr.end(); it1++)
        {
            /******Frequency of a value of an element already calculated  *****/
            bool checked = 0;
            /******Chech if calculated *****/
            for (it2 = arr.begin() - 1; it2 < it1; it2++)
            {
                if (*it2 == *it1)
                {
                    checked = 1;
                }
            }
            if (checked == 1)
            {
                continue;
            }

            count = 0;
            /******interate over the array to calculate the frequency *****/
            for (it3 = arr.begin(); it3 != arr.end(); it3++)
            {

                if (*it1 == *it3)
                {
                    count++;
                }
            }

            std::cout << "element: " << *it1 << " and count : " << count << std::endl;
        }
    }
    void RunCalculateFrequency(void)
    {
        WelecmeArray();
        CalculateFrequency();
    }
}
int main()
{
    CALCULATE_FREQUENCY::RunCalculateFrequency();

    return 0;
}