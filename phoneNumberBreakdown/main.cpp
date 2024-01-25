#include <iostream>
#include <string>

struct StructuredPhoneNumber {
    std::string areaCode;
    std::string exchange;
    std::string lineNumber;
};

bool operator==(const StructuredPhoneNumber& lhs, const StructuredPhoneNumber& rhs)
{
    return lhs.areaCode == rhs.areaCode && lhs.exchange == rhs.exchange && lhs.lineNumber == rhs.lineNumber;
}

bool isPhoneNumberValid(std::string phoneString)
{
    if(phoneString.length() != 10)
    {
        return false;
    }

    return true;

}

StructuredPhoneNumber parsePhoneNumber(long long int phoneNumber) {
    std::string areaCode;
    std::string exchange;
    std::string lineNumber;
    std::string phoneNumberString = std::to_string(phoneNumber);

    if(isPhoneNumberValid(phoneNumberString))
    {
        areaCode = phoneNumberString.substr(0, 3);
        exchange = phoneNumberString.substr(3, 3);
        lineNumber = phoneNumberString.substr(6, 4);

        return {areaCode, exchange, lineNumber};

    }
    return {"000", "000", "0000"};



}


int main() {
    long long int inputPhoneNumber{0};
    std::cin >> inputPhoneNumber;

    StructuredPhoneNumber structuredPhoneNumber = parsePhoneNumber(inputPhoneNumber);
    std::cout<< "Area Code: " << structuredPhoneNumber.areaCode << std::endl;
    std::cout<< "Exchange: " << structuredPhoneNumber.exchange << std::endl;
    std::cout<< "Line Number: " << structuredPhoneNumber.lineNumber << std::endl;


    return 0;
}
