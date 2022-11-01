#include <iostream>

int main()
{
    
    int *p = NULL;
    /* new is an operator*/
    p = new int;
    if(!p)
    {
        std::cout << "allocation of p failed" << std::endl;
    }
    int &ref = *p;
    float *f = new float(54.76);
    int n = 5;
    int *q = new int[5];
    std::cout << "adress of p : " << &ref << std::endl;
    std::cout << "adress of p : " << p << std::endl;
    std::cout << "adress of f : " << f << std::endl;
    std::cout << "adress of q : " << q << std::endl;
    std::cout << "value in f : " << *f << std::endl;
    std::cout << "value in p : " << *p << std::endl;
    std::cout << "value in q : " << *q << std::endl;
    /*When allocate -> deallocate*/
    /* new is an operator*/
    delete p;
    delete f;
    delete q;
    std::cout << "value in f : " << *f << std::endl;
    std::cout << "value in p : " << *p << std::endl;
    std::cout << "adress of p : " << p << std::endl;
    




    return 0;
}