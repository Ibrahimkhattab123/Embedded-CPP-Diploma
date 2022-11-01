#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::pair<int, std::string>> Vector1;

    //'a' 1
    Vector1.push_back(std::make_pair(1, "Ibrahim"));
    Vector1.emplace_back(2, "Hala");

    for (auto Element : Vector1)
    {
        std::cout << Element.first << "- " << Element.second << std::endl;
    }

    std::cout << std::endl;

    return 0;
}