#include <iostream>
#include <vector>

class Shape 
{
    public:
    Shape()
    {

    }
    virtual float CalculateArea() = 0;
    virtual void DisplayArea() = 0;
    virtual ~Shape() = default;
    


};
class Circle : public Shape 
{
    public:
    Circle(float radius) : m_radius(radius)
    {

    }
    float CalculateArea() override
    {
        constexpr double PI = 3.14;
        return 2*PI*m_radius*m_radius;  
    }
    void DisplayArea() override
    {
        std::cout << "Circle area = " << this -> CalculateArea() << std::endl; 
    }
    private:
    float m_radius;
      
};
class Rectangle : public Shape 
{
    public:
    Rectangle(float height, float width) : m_height(height), m_width(width)
    {

    }
    float CalculateArea() override
    {
        return m_height * m_width;  
    }
    void DisplayArea() override
    {
        std::cout << "Rectangle area = " << this -> CalculateArea() << std::endl; 
    }
    private:
    float m_height;
    float m_width;
      
};

void Draw_Shapes(std::vector<Shape*> shapes)
{
    for (auto shape : shapes)
    {
        shape -> CalculateArea(); 
        shape -> DisplayArea();
    }
}

int main()
{
    Shape *shape;
    Circle circle(10.0);
    Rectangle rectangle(4.5,3.5);
    shape = &circle;
    std::vector<Shape*> DrawVec;
    DrawVec.push_back(&circle);
    DrawVec.push_back(&rectangle);

    Draw_Shapes(DrawVec);


    

    return 0;
}