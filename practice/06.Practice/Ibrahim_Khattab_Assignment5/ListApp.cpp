#include "QUEUE.h"

int main()
{
    QUEUE<int> Queue1(10);
    for (int count = 0; count < 10; count++)
    {
        std::cout << Queue1.enqueue(count) << "\t";
    }
    std::cout << std::endl;
    for (int count = 0; count < 10; count++)
    {
        std::cout << Queue1.dequeue(count) << "\t";
    }

    return 0;
}