#include "QUEUE.h"

template <class T>
QUEUE<T>::QUEUE(int size): l_size(size){
    std::cout<< l_size ;
}
template <class T>
int QUEUE<T>::enqueue(const T &item)
{
    return this -> pushAtBack(item);
}
template <class T>
int QUEUE<T>::dequeue(T &item)
{
    return this -> removeFromFront(item);
}
template <class T>
bool QUEUE<T>::isQueueEmpty() const
{
    return this -> isEmpty();
}
template <class T>
bool QUEUE<T>::isQueueFull() const
{
    return this -> isFull();
}