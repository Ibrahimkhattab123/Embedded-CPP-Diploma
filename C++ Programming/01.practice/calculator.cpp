//get two number
//enters operations
//

#include <iostream>

namespace computing{
    std::int32_t firstNum;
    std::int32_t secondNum;
    std::int8_t operationType;
    std::int32_t result; 


    void welcomeToCalculator(){
        std::cout<< "please enter the first number" << std::endl;
        std::cin>> firstNum;
        std::cout<< "please enter the second number" << std::endl;
        std::cin >> secondNum;
        std::cout<< "please enter the operation type" << std::endl;
        std::cin >> operationType;
    }
     void ADD(){
        result = firstNum+secondNum;
     }
     void SUB(){
        result = firstNum-secondNum;
     }
     void MULTI(){
        result = firstNum*secondNum;
     }
      void DIV(){
        result = firstNum/secondNum;
     }
      void MOD(){
        result = firstNum%secondNum;
     }
    void runCode(){

        switch (operationType)
        {
        case '+':
           ADD();
            break;
        case '-':
           SUB();
            break;
        case '*':
           MULTI();
            break;
        case '/':
           DIV();
            break;   
         case '%':
           MOD();
            break; 
        default:
              std::cout<< "please enter a valid value" << std::endl;
            break;
        }
      std::cout<< "res = " << result <<  std::endl;
    
    }


}

int main(){
     
     computing::welcomeToCalculator();
     computing::runCode();
    




    return 0;
}