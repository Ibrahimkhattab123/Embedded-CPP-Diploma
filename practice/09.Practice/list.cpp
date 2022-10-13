#include "LIST.h"

template <typename NODE_T>
LIST<NODE_T>::LIST() : FirstPtr(nullptr), LastPtr(nullptr)
{
}

template <typename NODE_T>
bool LIST<NODE_T>::isEmpty() const
{
    return this->FirstPtr == nullptr;
}

template <typename NODE_T>
void LIST<NODE_T>::Insert_Node_At_Front(const NODE_T &Value)
{
    LinkedListNode<NODE_T> *TempPtr = this->getNewNode(Value);
    if (isEmpty())
    {
        this->FirstPtr = TempPtr;
        this->LastPtr = TempPtr; // One node
    }
    else
    {
        TempPtr->NextPtr = this->FirstPtr;
        this->FirstPtr = TempPtr;
    }
}

template <typename NODE_T>
void LIST<NODE_T>::Remove_Node_From_Front(NODE_T &Value)
{
    if (isEmpty())
    {
        std::cout << "List is Empty, Nothing to be removed" << std::endl;
    }
    else
    {
        LinkedListNode<NODE_T> *TempPtr = this->FirstPtr;
        if (FirstPtr == LastPtr) // One Node to remove
        {
            this->FirstPtr = nullptr;
            this->LastPtr = nullptr;
        }
        else
        {
            this->FirstPtr = this->FirstPtr->NextPtr; // make FirstPtr pointing to previous node
        }
        Value = TempPtr->nValue;
        delete TempPtr;
    }
}
template <typename NODE_T>
void LIST<NODE_T>::Display_Linked_List() const
{
    if (isEmpty())
    {
        std::cout << "List is empty!!" << std::endl;
        return;
    }
    else
    {
        LinkedListNode<NODE_T> *TempPtr = this->FirstPtr;
        while (TempPtr != nullptr)
        {
            std::cout << TempPtr->nValue << "   ";
            TempPtr = TempPtr->NextPtr;
        }
        std::cout << std::endl;
    }
}
template <typename NODE_T>
int LIST<NODE_T>::Linked_list_Lenght(LinkedListNode<NODE_T> &_list)
{
    int NodeCount = 0;
    LinkedListNode<NODE_T> *TempPtr = this->FirstPtr;
    while (TempPtr != nullptr)
    {
        std::cout << TempPtr << "   ";
        NodeCount++;
        TempPtr = TempPtr->NextPtr;
    }
    return NodeCount;
}
