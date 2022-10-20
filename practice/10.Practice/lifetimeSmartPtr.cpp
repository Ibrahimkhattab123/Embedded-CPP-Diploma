#include <iostream>
#include <memory>

void asSmartPtrGood(std::shared_ptr<int> Shared)
{
    std::cout << "Shared Good reference counter " << Shared.use_count() << std::endl;
    Shared.reset(new int(1998));
    std::cout << "Shared Good reference counter " << Shared.use_count() << std::endl;
}

void asSmartPtrBad(std::shared_ptr<int> &Shared)
{
    *Shared += 25;
    std::cout << "Shared Bad reference counter " << Shared.use_count() << std::endl;
}

int main()
{
    int Year = 1997;
    std::shared_ptr<int> ShPtr1 = std::make_shared<int>(Year);
    auto ShPtr2 = ShPtr1;

    std::cout << std::endl;

    std::cout << "ShPtr1 reference counter " << ShPtr1.use_count() << std::endl;
    std::cout << "ShPtr2 reference counter " << ShPtr2.use_count() << std::endl;

    std::cout << std::endl;

    asSmartPtrGood(ShPtr1);

    std::cout << std::endl;

    std::cout << "ShPtr1 " << *ShPtr1 << std::endl;
    std::cout << "ShPtr1 reference counter " << ShPtr1.use_count() << std::endl;

    std::cout << std::endl;

    std::cout << "ShPtr2 " << *ShPtr2 << std::endl;
    std::cout << "ShPtr2 reference counter " << ShPtr2.use_count() << std::endl;

    std::cout << std::endl;

    asSmartPtrBad(ShPtr2);

    std::cout << "ShPtr1 " << *ShPtr1 << std::endl;
    std::cout << "ShPtr1 reference counter " << ShPtr1.use_count() << std::endl;

    std::cout << std::endl;

    std::cout << "ShPtr2 " << *ShPtr2 << std::endl;
    std::cout << "ShPtr2 reference counter " << ShPtr2.use_count() << std::endl;

    std::cout << std::endl;

    // this will crash the programm
    ShPtr1.reset();
    // this line will decrement the reference count and delete the pointed-to object
    // esult in an empty shared_ptr that is just like a default-constructed one.
    // It's just like assigning the pointer to null, wich will effect all shared pointers pointing to that object
    // similar to
    // ShPtr1 = nullptr;
    // std::cout << "ShPtr1 " << *ShPtr1 << std::endl;
    // std::cout << "ShPtr1 reference counter " << ShPtr1.use_count() << std::endl;

    std::cout << std::endl;

    //By resetting a shared pointer like this, the pointer points to another object
    //so ShPtr2 still points at the first object
    ShPtr1.reset(new int(2030));
    //call destructor and decrement for the first object, and call constructor to the new object and increment count fot it 
    //Equivalent to shared_ptr().swap(*this);
    std::cout << "ShPtr1 " << *ShPtr1 << std::endl;
    std::cout << "ShPtr1 reference counter " << ShPtr1.use_count() << std::endl;

    std::cout << std::endl;

    std::cout << "ShPtr2 " << *ShPtr2 << std::endl;
    std::cout << "ShPtr2 reference counter " << ShPtr2.use_count() << std::endl;

    return 0;
}