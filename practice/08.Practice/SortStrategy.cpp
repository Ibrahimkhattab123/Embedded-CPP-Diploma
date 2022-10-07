#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Person
{
    std::string Name;
    uint32_t Adress_Nr;
};

int main()
{
    std::vector<Person> PersonVec(2);

    PersonVec[0].Name = "Ibrahim Khattab";
    PersonVec[0].Adress_Nr = 28;

    PersonVec[1].Name = "Rayyan Khattab";
    PersonVec[1].Adress_Nr = 39;

    auto Cmpname = [](const Person &first, const Person &second) -> bool
    {
        return first.Name > second.Name;
    };
    auto CmpAdress = [](const Person &first, const Person &second) -> bool
    {
        return first.Adress_Nr > second.Adress_Nr;
    };
    sort(PersonVec.begin(), PersonVec.end(), Cmpname); // depend on how insertion sort
    for (auto Elem : PersonVec)
    {
        std::cout << "PersonVec.name:" << Elem.Name << std::endl;
    }

    sort(PersonVec.begin(), PersonVec.end(), CmpAdress);

    for (auto Elem : PersonVec)
    {
        std::cout << "PersonVec.address:" << Elem.Adress_Nr << std::endl;
    }

    return 0;
}