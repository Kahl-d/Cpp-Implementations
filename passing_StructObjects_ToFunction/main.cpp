#include <iostream>
#include <string>



struct Cars{
    std::string name{""};
    int value{100};
};


void printCar(const Cars& car){
    std::cout << "Name: " << car.name << std::endl;
    std::cout << "Value: " << car.value << std::endl;
}

bool operator == (const Cars& car1, const Cars& car2){
    return car1.name == car2.name && car1.value == car2.value;
}

bool operator ==({std::string name, std::string value}, std::string );
//why cant i pass object as struct binding
//why cant i pass object as struct binding
//why cant i pass object as struct binding

int main() {
    Cars car1{
        "Ferrari",
        100000
    };

    Cars car2{
        "Lamborghini",
        200000
    };

    printCar({"Ferrai", 100000});
    if(car1 == {"Ferrari", 100000"})
    {
        std::cout << "Car1 and Car2 are the same" << std::endl;
    } else {
        std::cout << "Car1 and Car2 are not the same" << std::endl;
    }


    return 0;
}
