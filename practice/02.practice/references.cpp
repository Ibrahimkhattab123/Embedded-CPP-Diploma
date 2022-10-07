#include <iostream>


int main()
{
    int x = 5;
    int &r = x;
    int *p = &x;

    printf(" adress of x = %x, adress of r = %x \n", &x, &r);
    printf(" adress of x = %x, adress of p = %x \n", &x, &p);
    std::cout << r << std::endl; 



    return 0;
} 