#include "IntegerArray.h"


int main()
{
    
     // 1)

    integer_array<int, bool> FirstArray(1);
    FirstArray.Square_Element();
    FirstArray.Print_Elements();

    // 2)

    integer_array<int, bool> SecondArray(0);
    SecondArray.Pushback_Given_Element(2);
    SecondArray.Print_Elements();
    
    return 0;
}