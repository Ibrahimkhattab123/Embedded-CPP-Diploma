#include <iostream>
#include <list>
#include <algorithm>
#include <array>
#include <iterator>
#include <string>
#include <cassert>

struct President
{
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
    President(President &&other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }
    President &operator=(const President &other) = default;
};

// std::list is a container that supports constant time insertion
// and removal of elements from anywhere in the container.
// Fast random access is not supported.
// It is usually implemented as a doubly-linked list.
// Compared to std::forward_list
// std::list container provides bidirectional iteration capability while being less space efficient.

int main()
{
    // this is a constuctor for a list, there is many types of overloaded constructors
    // using them we can initiailize a list for specific reasons
    // std::list constructor calls alloc function, and it's
    // An allocator that is used to acquire/release memory and to construct/destroy the elements in that memory.
    // Of course there is a desstuctor
    std::list<int> List1(10), List2;

    // to assign values we can ust operator (=), assign method
    // this is too an overloaded method
    // first we can set a initialized list as parameter: List1.assign({1, 2, 3});
    // second, we can use like this list.assign(sizeToFill, ValueToFill): List2.assign(5, 100);
    // thiurd, assign element of other container: List2.assign(List1.begin(), List1.end());
    // and give a bounderies of elemnts tho be filled list.assign(container.first(),container.end())
    List1.assign({1, 2, 3});

    List2.assign(5, 100);

    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    List2.assign(List1.begin(), List1.end());
    std::cout << "List2:";

    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    // we can allocate memory for a conainer using the allocaor
    constexpr int LsSize = 5;
    List1.get_allocator().allocate(LsSize);
    List1.assign(LsSize, 200);
    std::cout << "List1 after memory allocation" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    // Accessing an element
    // front: access first Element
    // back: acsses last element
    std::cout << "first element in List1: " << List1.front()
              << ", first element in List2: " << List2.front() << std::endl
              << "last element in List1: " << List1.back()
              << ", last element in List2: " << List2.back() << std::endl;

    // Iterators: we have several ways to iterate over a container
    // 1)begin, cbegin: returns an iterator to the beginning
    // 2)end, cend: returns an iterator to the end
    // 3)rbegin, crbegin: returns a reverse iterator to the beginning
    // 4)rend, crend: returns a reverse iterator to the end

    // Square numbers in List2
    std::for_each(List2.begin(), List2.end(), [](int &n) -> int
                  { n *=n;
                    return n; });

    std::cout << "List2 after squared" << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::for_each(List2.rbegin(), List2.rend(), [&](int &n)
                  { std::cout << n << "  "; });

    std::cout << std::endl;

    // container's capacity
    // cheching if a container is empty or not
    // Or using empty() method
    if (List1.begin() != List1.end())
    {
        std::cout << "List is not empty" << std::endl;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
    if (!List1.empty())
    {
        std::cout << "List is not empty" << std::endl;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
    std::cout << "Is List1 empty? " << List1.empty() << std::endl;

    // check size of a container
    std::cout << "List1 size: " << List1.size() << std::endl;
    // max_size(): returns the maximum possible number of elements
    std::cout << "List1 size: " << List1.max_size() << std::endl;

    // modifiers
    // clear: clear the content of a container
    // insert: insert element
    // ersae: erase element/elements
    // push_back: push an element to the end
    // emplace_back: constructs an element in-place at the end
    // pop_back: removes the last element
    // push_front: inserts an element to the beginning
    // emplace_front: constructs an element in-place at the beginning
    // pop_front: removes the first element
    // resize: changes the number of elements stored
    // swap: swaps the contents

    List1.clear();
    std::cout << "After clear(), Is List1 empty? " << List1.empty() << std::endl;
    // insert 1 at the front
    List1.insert(List1.begin(), 1);
    // inert 2 two times at the front
    List1.insert(List1.begin(), 2, 2);
    // insert elemnt of List2 after the third
    // std::next(iterator, nth position): Return the nth successor of iterator it.
    List2.insert(std::next(List1.begin(), 3), List2.begin(), List2.end());
    // instert initialzed list
    List1.insert(List1.end(), {1, 2, 3});

    std::cout << "List1 after insertion" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    // emplace(), iterator emplace( const_iterator pos, Args&&... args );
    List1.clear();
    // emolace atr the the front
    List1.emplace(List1.begin(), 1);
    List1.emplace(List1.end(), 2);
    List1.emplace(List1.begin(), 3);
    List1.emplace(std::next(List1.begin(), 2), 1);
    std::list<std::pair<int, char>> List3;
    List3.emplace(List3.begin(), 1, 'a');
    List3.emplace(List3.begin(), 2, 'b');

    std::cout << "List1 after emplacing" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::cout << "List3 after insertion with std::pair" << std::endl;
    std::cout << "List3:";
    for (auto Element : List3)
    {
        std::cout << Element.first << " - " << Element.second << std::endl;
        ;
    }

    // erase an element
    // erase(position)
    List1.insert(List1.begin(), 9);
    List1.insert(List1.begin(), 1);
    List1.insert(List1.begin(), 2);
    List1.insert(List1.end(), 9);
    List1.insert(List1.end(), 1);
    List1.emplace(List1.end(), 9);
    List1.erase(List1.begin());
    std::list<int>::iterator range_begin = List1.begin();
    std::list<int>::iterator range_end = List1.begin();
    std::advance(range_begin, 2);
    std::advance(range_end, 5);
    List1.erase(range_begin, range_end);
    std::cout << "List1 after erasing" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    for (std::list<int>::iterator it = List1.begin(); it != List1.end();)
    {
        if (*it == 1)
            it = List1.erase(it);
        //  List1.erase(it); must be assigned so the iterator can point to the next element of erased element
        // The iterator returned from a.erase(q)
        // points to the element immediately following q prior to the element being erased.
        // If no such element exists, a.end() is returned.
        else
            ++it;
    }
    std::cout << "List1 after erasing" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    // emplace_back(value) and can be implemented with pair too
    List1.emplace_back(20);
    // when values emplaced to list of type struct or class then constructor values can be emplaced
    // President is a struct
    std::list<President> elections;
    // auto &ref = elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    // pop_back()
    List1.pop_back();
    // push_front()
    List1.push_front(13);
    int x = 3;
    List1.push_front(x);
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    // emplace_front(): like emplace_back
    List1.emplace_front(15);
    List1.emplace_front(13);
    // pop_front like pop_back
    List1.pop_front();
    // resize(size): resize the container and can assign value to the added memory
    List1.resize(40); // value will be zero for the added element (memory)
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List1.resize(3);
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List1.resize(7, 3); // resize to 7 and assigen added elements to 3
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    // operartions that we can do on a list like:
    // sort(): sorts a list in ascending order
    // merge(): merges two sorted lists
    // reverse(): reverse the order
    // splice(): move elemnts of a list to other
    // remove () and remoive_if(): remove elements under a given condition
    // unique(): removes consecutive duplicate elements

    List1.assign({1, 8, 20, 3, 4, -1, 2, 10, 30, 210});
    std::cout << "List1 before sorting" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    List1.sort();
    std::cout << "List1 after sorting" << std::endl;
    std::cout << "List1 sorted in ascending order" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List1.reverse(); // we can use List1.sort(std::greater<int>());, we give a comparision function
                     //  the object function satisfies the requirements of Compare (BinaryPridicate)
    std::cout << "List1 after reversing" << std::endl;
    std::cout << "List1 sorted in descending order" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    List1.splice(List1.begin(), List2);
    std::cout << "List1 after splicing" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    auto it = List1.begin();
    std::advance(it, 3); // Increments given iterator it by n elements.same as  std::next(List1.begin(), 3)
    List2.splice(List2.begin(), List1, it, List1.end());
    std::cout << "List1 after splicing" << std::endl;
    std::cout << "List1:";
    for (auto Element : List1)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;

    List2.remove(4);
    List2.remove_if([](int n)
                    { return n > 10; });
    std::cout << "after remove: " << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List2.assign({1, 1, 5, 3, 6, 8, 5, 2, 1, 1, 3, 5, 7, 5, 8, 5, 5, 3});
    std::cout << "before unique()" << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List2.unique();
    std::cout << "after unique()" << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    List2.unique([](int n1, int n2) {return ((n1%3) == (n2%3));});
    std::cout << "after unique()" << std::endl;
    std::cout << "List2:";
    for (auto Element : List2)
    {
        std::cout << Element << "  ";
    }
    std::cout << std::endl;
    return 0;
}