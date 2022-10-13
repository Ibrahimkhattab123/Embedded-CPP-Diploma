#ifndef _LINKEDLISTNODE_H
#define _LINKEDLISTNODE_H


template <typename NODE_T> class LIST;

template <typename NODE_T>
class LinkedListNode
{
    friend class LIST<NODE_T>;
public:
    LinkedListNode(const NODE_T &Value);
    NODE_T Get_Value() const;
   

private:
    NODE_T nValue;
    LinkedListNode<NODE_T> *NextPtr;
};


template class LinkedListNode<int>;


#endif // _LINKEDLISTNODE_H