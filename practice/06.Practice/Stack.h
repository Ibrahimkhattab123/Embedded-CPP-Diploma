#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

template <class T>
class STACK
{
    public:
    STACK(int = 10);
    ~STACK() { delete [] stackPtr;}
    int push(const T&);
    int pop(T&);
    int isEmpty() const { return s_top == -1;}
    int isFull()  const { return s_top == s_size - 1;}

    private:
    int s_size;
    int s_top;
    T *stackPtr;
};

template <class T>
STACK<T>::STACK(int size)
{
    s_size = ((size > 0) && (size < 1000)) ? size : 10;
    s_top = -1;
    stackPtr = new T[s_size];
}

template <class T>
int STACK<T>::push(const T &item)
{
    if (!isFull())
    {
        stackPtr[++s_top] = item;
        return 1;
    }
    return 0;
}
template <class T>
int STACK<T>::pop(T &pop_item)
{
    if (!isEmpty())
    {
        pop_item = stackPtr[s_top--];
    }
    return 0;
}




#endif