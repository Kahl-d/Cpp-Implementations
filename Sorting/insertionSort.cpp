#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct TokenFreq{
    std::string token{""};
    int freq{0};
};

//function prototypes
int getTokenFreq (TokenFreq freqToken);
TokenFreq operator+(TokenFreq lhs, TokenFreq rhs);
bool operator<=(TokenFreq lhs, TokenFreq rhs);
std::ostream& operator<<(std::ostream& out, const TokenFreq printToken);

void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);  //
void selectionSort(std::vector<TokenFreq>& tokFreqVector );
void insertionSort(std::vector<TokenFreq>& tokFreqVector );


int main()

{


    return 0;
}

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

void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec){
    std::istringstream inSS(istr);
    tfVec.resize(0);

    std::string word;

    while(inSS >> word)
    {

        std::transform(word.begin(),word.end(),word.begin(), [](char c){return std::tolower(c);});

        auto p = std::find_if(tfVec.begin(), tfVec.end(), [word](TokenFreq t){return t.token == word ;});
        if(p == tfVec.end())
        {
            TokenFreq newToken;
            newToken.token = word;
            newToken.freq = 1;
            tfVec.push_back(newToken);

        }
        else
        {
            p->freq++;
        }

    }
}


