#include "LIST.h"

int main()
{
    LIST<int> IntList;
    IntList.Insert_Node_At_Front(10);
    IntList.Insert_Node_At_Front(20);
    IntList.Insert_Node_At_Front(130);
    IntList.Insert_Node_At_Front(40);
    IntList.Insert_Node_At_Front(50);
    IntList.Insert_Node_At_Front(60);
    IntList.Display_Linked_List();

    int RemoveVal = 10;
    IntList.Remove_Node_From_Front(RemoveVal);
    IntList.Display_Linked_List();
    IntList.Remove_Node_From_Front(RemoveVal);
    IntList.Display_Linked_List();
    IntList.Remove_Node_From_Front(RemoveVal);
    IntList.Display_Linked_List();

    return 0;
}