//implement the functions declared in tokenFreq.h
// namely,
// - getTokenFreq()'s prototype
// - the two sorting algorithms' prototypes

//remember to include all the function defintions in the declared namespace NS_TOKEN_FREQ
//in the following fashion:
// namespace NS_TOKEN_FREQ{
//       //define the first function here
//       //define your second function here
//       ...
//}

#include <iostream>
#include "tokenFreq.h"

namespace NS_TOKEN_FREQ{



    int getTokenFreq(TokenFreq freqToken){

        return freqToken.freq;

    }

    //Overloading + to add to tokens
    TokenFreq operator+(TokenFreq lhs, TokenFreq rhs){
        std::string addedToken{""};
        int addedFreq{getTokenFreq(lhs) + getTokenFreq(rhs)};

        addedToken = lhs.token + " or " + rhs.token;

        return {addedToken, addedFreq};

    }

    //Overlaoding <= operator to compare freq of tokens

    bool operator<=(TokenFreq lhs, TokenFreq rhs){

        return getTokenFreq(lhs) <= getTokenFreq(rhs);

    }

    //Overloading << operator to print TokenFreq struct

    std::ostream& operator<<(std::ostream& out, const TokenFreq printToken){

        std::string print{""};

        out << "( token, freq ) = ( " + printToken.token + ", ";

        out<< printToken.freq;
        out<<" )";

        return out;
    }


    void getTokenFreqVec(std::string& istr){
        std::istringstream inSS(istr);

        std::string word;
        while(inSS >> word)
        {
            std::cout<<word;
        }
    }


}

