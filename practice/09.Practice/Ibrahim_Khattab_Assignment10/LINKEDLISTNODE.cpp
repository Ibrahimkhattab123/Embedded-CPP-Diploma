#include "LINKEDLISTNODE.h"


template <typename NODE_T>
LinkedListNode<NODE_T>::LinkedListNode(const NODE_T &Value)
            : nValue(Value), NextPtr(nullptr)
{
}

template <typename NODE_T>
NODE_T LinkedListNode<NODE_T>::Get_Value() const
{
    return this->nValue;
}