#include <iostream>
#include <functional>
#include <algorithm>

/*template function*/
template < class T>
T MAX (T &a, T&b)
{
    return ((a > b) ? a : b);
}

template <class S>
void SWAP (S &a, S &b)
{
    S temp = a;
    a = b;
    b = temp;


}

template <class T>
void sort(T::iterator first, T::iterator second, std::function<bool (T& a, T& b)>);

int main ()
{

    return 0;
}