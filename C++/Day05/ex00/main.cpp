#include "Bureaucrat.hpp"

int main (){
    Bureaucrat b("Hermes", 36);

    std::cout << b;
    try{
        while (1){
            b.gradeinc();
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        while (1){
            b.gradedec();
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}