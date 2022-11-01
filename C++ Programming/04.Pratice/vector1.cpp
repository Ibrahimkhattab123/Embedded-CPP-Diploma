#include <iostream>
#include <vector>

void InputVector(std::vector<int> &vec);
void OutputVector(const std::vector<int> &vec);

int main ()
{
    std::vector<int> v(3);

    InputVector(v);

    std::cout << "Vector's size: " << v.size() << " ,Capacity: " << v.capacity() << std::endl;

    v.push_back(9);
    v.push_back(15); 

    OutputVector(v);

    std::cout << "Vector's size: " << v.size() << " ,Capacity: " << v.capacity() << std::endl;

    v.push_back(17);
    v.push_back(18);

    std::cout << "Vector's size: " << v.size() << " ,Capacity: " << v.capacity() << std::endl;

    for (int elem : v)
    {
        std::cout << elem << std::endl; 
    }


    return 0;
}
void InputVector(std::vector <int> &vec)
{
    for (int &elem : vec)
    {
        std::cin >> elem; 
    }

}
void OutputVector(const std::vector<int> &vec)
{
    for (int elem : vec)
    {
        std::cout << elem << std::endl; 
    }
}