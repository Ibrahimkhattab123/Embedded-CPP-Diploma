#include <iostream>


int main(){

    std::string firstName = "Ibrahim";
    std::string lastName  = " Khattab";
    std::string name      = firstName + lastName;

    std::cout << "Name entered is: " << name << ",and the size of the name: "<< sizeof(name) << std::endl;


    return 0;
}