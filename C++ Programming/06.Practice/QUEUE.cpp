#include "QUEUE.h"

template <class T>
QUEUE<T>::QUEUE(int Size)
{
    l_size = ((size > 0) && (size < 1000)) ? size : 10;
    ListPtr = new T[l_size];
    l_last = -1;
    l_first = *ListPtr;
}
template <class T>
int QUEUE<T>::enqueue(const T &item)
{
    return this->pushAtBack(item);
}
template <class T>
int QUEUE<T>::dequeue(T &item)
{
    return this->removeFromFront(item);
}
template <class T>
bool QUEUE<T>::isQueueEmpty() const
{
    return this->isEmpty();
}
template <class T>
bool QUEUE<T>::isQueueFull() const
{
    return this->isFull();
}