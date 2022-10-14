#include <iostream>
#include <string.h>

class String
{
public:
    String(const char *str)
    {
        std::cout << "created" << std::endl;
        this->StrSize = strlen(str);
        this->StrData = new char[StrSize];
        memcpy(this->StrData, str, StrSize);
    }
    String(const String &StrObj)
    {
        std::cout << "copied" << std::endl;
        this->StrSize = StrObj.StrSize;
        this->StrData = new char[StrSize];
        memcpy(this->StrData, StrObj.StrData, StrSize);
    }
    String(String &&StrObj)
    {
        std::cout << "moved" << std::endl;
        this->StrSize = StrObj.StrSize;
        this->StrData = StrObj.StrData;

        StrObj.StrSize = 0;
        StrObj.StrData = nullptr;
    }
    ~String()
    {
        delete this->StrData;
    }
    void Print_Str()
    {
        for (int count = 0; count <= this->StrSize; count++)
        {
            std::cout << this->StrData[count];
        }
        std::cout << std::endl;
    }

private:
    char *StrData;
    uint32_t StrSize;
};

class Entity
{
public:
    Entity(const String &Obj) : StrObj(Obj)
    {
    }
    Entity(String &&Obj) : StrObj(std::move(Obj))
    {
    }

    void printName()
    {
        StrObj.Print_Str();
    }

private:
    String StrObj;
};

int main()
{
    Entity Name(String("Ibrahim Khattab"));
    Name.printName();

    String str("RoboticsCorner");
    Entity entity(std::move(str));
    entity.printName();

    return 0;
}
