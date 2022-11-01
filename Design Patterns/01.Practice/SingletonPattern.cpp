#include <iostream>

class singleton
{
    public:
    static singleton *getInstance();
    private:
    singleton(){}
    singleton(const singleton&);
    const singleton& operator= (const singleton&);
    static singleton* instance;
};

singleton* singleton::instance = 0;

singleton* singleton::getInstance()
{
    if (!instance)
    {
        instance = new singleton();
        std::cout <<  "getInstance(): First instance" << std::endl;
        return instance;
    }
    else 
    {
        std::cout << "getInstance():previous instance, was invoked once." << std::endl;
        return instance;
    }
}

int main ()
{
    singleton *s1 = singleton::getInstance();
    singleton *s2 = singleton::getInstance();
    
    return 0;
}