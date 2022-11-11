#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>

template <class T>
class BinarySearch
{
public:
    explicit BinarySearch(std::vector<T> _Vector, T _SearchElement)
        : Vector(_Vector), SearchElement(_SearchElement) {}

    int SearchBinary ();
private:
    std::vector<T> Vector;
    T SearchElement;
};

template <class T>
int BinarySearch<T>::SearchBinary()
{
    std::sort( Vector.begin(), Vector.end(), 
                            []( T a, T b){return ((std::abs(a)) < (std::abs(b)));} );

    std::cout << "Vector after sorting: " << std::endl;

    std::for_each(Vector.begin(), Vector.end(), 
                            [](T a){std::cout << a << "  ";});
    std::cout << std::endl;
    T first = 0; 
    T last = Vector.size() - 1;

    bool found = false;

    while ((last - first > 1) && (!found))
    {
        T midPoint = (first + last )/2;

        if (SearchElement >= midPoint)
        {
            first = midPoint + 1;
        }
        else
        {
            last = midPoint;
        }
    }

    if (Vector[first] == SearchElement)
    {
        std::cout << "Elment Found at: " << first << "." << std::endl;
        return first;
    }
    else if (Vector[last] == SearchElement) 
    {
        std::cout << "Elment Found at: " << last << "." << std::endl;
        return last;
    }
    else
    {
        std::cout << "Element not found." << std::endl;
        return 0;
    }
    
}

int main ()
{
    std::vector<int> _Vector = {1,4,3,7,6,3,0,5};
    int element = 4;

    BinarySearch<int> doBinary(_Vector, element);

    doBinary.SearchBinary();

    return 0;
}