#include "COMPOSE.h"

int main ()
{
    Page p1("p1");
    Page p2("p2");
    Copy book("book");
    Copy novel("novel");

    book.addCopyElement(p1);
    book.addCopyElement(p2);
    book.addItem(p1);
    book.removeItem();
    p1.addItem(p2);
    p1.removeItem();
    


    return 0;
}