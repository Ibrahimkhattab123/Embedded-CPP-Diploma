#ifndef COMPOSE_H
#define COMPOSE_H

#include <iostream>
#include <vector>

class PageObject
{
public:
    virtual void addItem(PageObject l) {}
    virtual void removeItem() {}
    virtual void deleteItem(PageObject l) {}
};
class Page : public PageObject
{
public:
    Page(std::string name) : PageName(name) {}
    virtual void addItem(PageObject l)
    {
        std::cout << "add item to page: " << this->PageName << std::endl;
    }
    virtual void removeItem()
    {
        std::cout << "remove item from page: " << this->PageName << std::endl;
    }
    virtual void deleteItem(PageObject l)
    {
        std::cout << "delete item from page: " << this->PageName << std::endl;
    }

private:
    std::string PageName;
};
class Copy : public PageObject
{
public:
    Copy(std::string name) : CopyName(name) {}
    void addCopyElement(PageObject l)
    {
        CopyVec.push_back(l);
    }
    virtual void addItem(PageObject l)
    {
        std::cout << "add item to copy: " << this->CopyName << std::endl;
    }
    virtual void removeItem()
    {
        std::cout << "remove item from copy: " << this->CopyName << std::endl;
    }
    virtual void deleteItem(PageObject l)
    {
        std::cout << "delete item from copy: " << this->CopyName << std::endl;
    }

private:
    std::vector<PageObject> CopyVec;
    std::string CopyName;
};

#endif // COMPOSE_H