#ifndef _INTEGERARRAY_H
#define _INTEGERARRAY_H

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

template <class ArrayType, class TaskType>
class integer_array
{
public:
    integer_array(TaskType Task)
    {
        if (Task == 1)
        {
            this->iVector = this->ArrayFirstAssignmrnt;
        }
        else
        {
            this->iVector = this->ArraySecondAssignmrnt;
        }
    }
    void Square_Element()
    {
        //  for (auto &Element : iVector)
        // {
        //      Element *= Element;
        //  }
        // Or using the algorithms library and lambda function
        std::for_each(iVector.begin(), iVector.end(), [](auto &Element) -> void
                      { Element *= Element; });
    }
    void Pushback_Given_Element(ArrayType PushBackElement)
    {

        
        for (ArrayType VecIterator = 0; VecIterator < iVector.size(); VecIterator++)
        {

            if (iVector.at(VecIterator) == PushBackElement)
            {
                iVector.erase(iVector.begin() + VecIterator);
                iVector.push_back(PushBackElement);
            }
        }
    }
    void Print_Elements()
    {
        for (auto &Element : iVector)
        {
            std::cout << Element << "     ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<ArrayType> iVector;
    std::vector<ArrayType> ArrayFirstAssignmrnt = {1, 5, 6, 7, 8, 9};
    std::vector<ArrayType> ArraySecondAssignmrnt = {1, 2, 3, 2, 10, 9, 2, 27, 30, 17, 8, 9};
};

#endif // _INTEGERARRAY_H