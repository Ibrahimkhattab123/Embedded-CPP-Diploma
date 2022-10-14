#include <iostream>
#include <memory>

constexpr float PI = 3.14;
class Circle
{
    public:
    Circle(float r ) : Radius(r){}
    float Calculate_Area()
    {
        return Radius * PI;
    }
    private:
    float Radius;
};


int main()
{
    auto C1 = std::make_unique<Circle>(5.2);
    //or like this:

    //std::unique_ptr<Circle> C1(new Circle(5.2));
    //std::unique_ptr<Circle> C1 = std::make_unique<Circle>(5.2); 

    //using make_unique<> is cleaner
    
    std::cout<< C1->Calculate_Area() << std::endl;
    
    //we can not copy make unique pointer pointing to other data type
    //solution by using th move semantic in c++
    //std::unique_ptr<Circle> C2(C1);
    std::unique_ptr<Circle> C2;
    C2 = std::move(C1);
   // std::cout<< C1->Calculate_Area() << std::endl;
    std::cout<< C2->Calculate_Area() << std::endl;

    return 0;
}