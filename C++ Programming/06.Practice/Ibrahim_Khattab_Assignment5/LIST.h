#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class LIST
{
public:
    LIST(int size);
    ~LIST();
    bool isEmpty() const;
    bool isFull() const;
    int pushAtBack(const T &item);
    int insertAtFront(const T &item);
    int removeFromBack(T &item);
    int removeFromFront(T &item);
protected:
    int l_size;
private:
    T data;
    T l_first;
    T l_last;
    T *ListPtr;
};

template class LIST<int>;
#endif // LIST_H