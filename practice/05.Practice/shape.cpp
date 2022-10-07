#include <iostream>

class Shape 
{
    public:
    Shape()
    {

    }
    virtual void Draw()
    {
        std::cout << "draw shape " << std::endl;
    }


};
class Circle : public Shape 
{
    public:
    Circle()
    {

    }
    void Draw()
    {
        std::cout << "draw circle " << std::endl;
    } 
    double Area(int radius)
    {
        constexpr double PI = 3.14;
        return 2*PI*radius*radius;
    }  
};

int main()
{
    Shape *shape;
    Circle circle;
    shape = &circle;
    shape -> Draw();


    return 0;
}