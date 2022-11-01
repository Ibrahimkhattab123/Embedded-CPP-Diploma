#include <iostream>
#include <memory>

class Subject
{
public:
    virtual void Define_Protcol() = 0;
    virtual void Request() = 0;
    ~Subject() {}
};

class RealSubject : public Subject
{
public:
    void Define_Protcol()
    {
    }
    void Request()
    {
        std::cout << "RealSubject.Request" << std::endl;
    }
};

class Proxy : public Subject
{
private:
   std::unique_ptr<Subject> realSubject;

public:
    Proxy() : realSubject(std::make_unique<RealSubject>())
    {
    }

    ~Proxy()
    {
       
    }
    void Define_Protcol()
    {
        realSubject->Request();
    }
    void Request()
    {
        realSubject->Request();
    }
};

int main()
{
    Proxy proxy;
    proxy.Request();
}