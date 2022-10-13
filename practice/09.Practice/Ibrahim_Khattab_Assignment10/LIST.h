#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include "LINKEDLISTNODE.h"

template <typename NODE_T>
class LIST 
{
public:
    LIST();
    ~LIST(){}
    bool isEmpty() const;
    void Insert_Node_At_Front(const NODE_T &Value);
    void Remove_Node_From_Front(NODE_T &Value);
    void Display_Linked_List() const;
    int Linked_list_Lenght(LinkedListNode<NODE_T> &_list);

private:
    LinkedListNode<NODE_T> *FirstPtr{nullptr};
    LinkedListNode<NODE_T> *LastPtr{nullptr};
    LinkedListNode<NODE_T> *getNewNode(const NODE_T &Value)
    {
        return new LinkedListNode<NODE_T>(Value); //create new node
    }
};

template class LIST<int>;
#endif //_LIST_H