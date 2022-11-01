#include <iostream>

namespace MySTD
{
    class smartPtr
    {
    private:
       int *ptr;
    public:
        smartPtr(int *p);
        ~smartPtr();
        int& operator*();
    };
    
    smartPtr::smartPtr(int *p = NULL)
    {
        ptr = p;
    }
    
    smartPtr::~smartPtr()
    {
        delete(ptr);
    }
    int& smartPtr::operator*()
    {
        return *ptr;
    }
    
}

int main()
{
    MySTD::smartPtr ptr(new int());
    *ptr = 60;

    std::cout << *ptr << std::endl; 
    
    return 0;
}