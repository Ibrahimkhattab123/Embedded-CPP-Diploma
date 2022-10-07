#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <functional>

/*
std :: string str_ = "AUstralian FrencH WimBleDon Us";

    all the sentence letters are written in lowercase 
    USE LAMBDA
*/
void strLowerCase (std::string str, std::function<void (char &ch)> lambdatoLow)
{
    for ( char &element : str)
    {
        lambdatoLow(element);
    }
    std::cout << str<< std::endl;

}

int main()
{
    std::string strToLowerCase = "AUstralian FrencH WimBleDon Us";
    /* Method 1, with algorithm for each and calling it*/
    auto lambdatoLow = [](char &element)-> void
    {
        if (isupper(element))
        {
           element = tolower(element);
        }
    };
    std::for_each(strToLowerCase.begin(), strToLowerCase.end(), lambdatoLow);
    std::cout << strToLowerCase << std::endl;
    /* Method 1, with calling lambda function in a function*/
    strToLowerCase = "AUstralian FrencH WimBleDon Us";
    strLowerCase(strToLowerCase, lambdatoLow);

    return 0;
}