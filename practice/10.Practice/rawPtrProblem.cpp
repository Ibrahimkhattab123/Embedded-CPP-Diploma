#include <iostream>

void fun()
{
    char *ptr = new char[10]; //heap
     delete ptr;  
     delete ptr; //double freeing

    //some logic
    memcpy(ptr,"string",10); //dangling pointer
   
}
int main()
{

   while(1)
    {
        fun(); //memory leak problem without deletion 
    }


    return 0;
}