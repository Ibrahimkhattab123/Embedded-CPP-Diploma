#include "LIST.h"

//template <class T>
//LIST<T>::LIST(int size)
//{
//    l_size = ((size > 0) && (size < 1000)) ? size : 10;
//    ListPtr = new T[l_size];
//    l_last = -1;
//    l_first = *ListPtr;
//}
//template <class T>
//LIST<T>::~LIST() { delete[] ListPtr; }

template <class T>
bool LIST<T>::isEmpty() const { return l_first == -1; }
template <class T>
bool LIST<T>::isFull() const { return l_last == l_size - 1; }
template <class T>
int LIST<T>::pushAtBack(const T &item)
{
    if (!isFull())
    {
        ListPtr[++l_last] = item;
        return 1;
    }
    return 0;
}
template <class T>
int LIST<T>::pushAtFront(const T &item)
{
    if (!isEmpty())
    {
        ListPtr[--l_first] = item;
        return 1;
    }
    return 0;
}
template <class T>
int LIST<T>::removeFromBack( T &item)
{
    if (!isEmpty())
    {
        item = ListPtr[l_last--];
        return 1;
    }
    return 0;
}
template <class T>
int LIST<T>::removeFromFront( T &item)
{
    if (!isEmpty())
    {
        item = ListPtr[l_first++];
        return 1;
    }
    return 0;
}
template <class T>
void LIST<T>::SetListSize(const int size)
{
    this -> l_size;
}
template <class T>
void LIST<T>::PrintList() const
{
    for (int Counter = 0; Counter < this->l_size; Counter++)
    {
        std::cout << ListPtr[Counter] << "  ";
    }
    std::cout << std::endl;
}

