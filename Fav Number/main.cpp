#include <iostream>
#include <string>

int main(){
    std::string nameI{};
    std::string nameType{};
    std::string sentence{};
//    std::cout<< "What is your favourite word?" << std::endl;
//    std::cin>> nameI;
//
    nameType = "     Khalid     asas";

    std::cout<< "What is your favourite sentence?" << std::endl;
    std::getline(std::cin, sentence);


//    std::cout<<nameI<<std::endl;
    std::cout<<nameType<<std::endl;
    std::cout<<sentence<<std::endl;




    return 0;
}


