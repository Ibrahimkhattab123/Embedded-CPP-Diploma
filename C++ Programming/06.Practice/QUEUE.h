#ifndef QUEUE_H
#define QUEUE_H

#include "LIST.h"

template < class T >
class QUEUE : public LIST<T>
{
    public:
    QUEUE(int Q_Size);
    int enqueue(const T &item);
    int dequeue(T &item);
    bool isQueueEmpty() const;
    bool isQueueFull() const;
    

};

template class QUEUE<int>;
#endif //QUEUE_H