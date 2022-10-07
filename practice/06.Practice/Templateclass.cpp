#include "Stack.h"

int main ()
{
    STACK<float> fs(13);
    float f = 3.3;

    fs.push(10.5);
    fs.pop(f);
    std::cout << f << std::endl;

    while(fs.push(f))
    {
       std::cout << f << "\t";
       f += 1.2;
    }
    std::cout << std::endl << "Stack is full "<< std::endl;

    while (fs.pop(f))
    {
        std::cout << f << "\t";
    }
    std::cout << std::endl << "Stack is empty "<< std::endl;


    
    STACK<int> is;
    int i = 9;


    while(is.push(i))
    {
       std::cout << i << "\t";
       i += 2;
    }
    std::cout << std::endl << "Stack is full "<< std::endl;
    while (is.pop(i))
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl << "Stack is empty "<< std::endl;

    





    return 0;
}