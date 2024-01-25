//This is a header file: to declare the TokenFreq data structure, the getTokenFreq() prototype,
//and other relevant function prototypes such as the overloaded operators for the TokenFreq datatype

//-include the above in the namespace NS_TOKEN_FREQ

//Note: please include <algorithm> in this file. The instructor's unit tests will need this libary.


#ifndef _TOKEN_FREQ_          //Beginning of header guard _TOKEN_FREQ_
#define _TOKEN_FREQ_

#include <sstream>
#include <string>
#include <vector>


namespace NS_TOKEN_FREQ{
    struct TokenFreq{
        std::string token{""};
        int freq{0};
    };

    //function prototypes
    int getTokenFreq (TokenFreq freqToken);
    TokenFreq operator+(TokenFreq lhs, TokenFreq rhs);
    bool operator<=(TokenFreq lhs, TokenFreq rhs);
    std::ostream& operator<<(std::ostream& out, const TokenFreq printToken);


    //Additional functional prototypes with vectors
    void getTokenFreqVec(std::string& istr);  //, std::vector<TokenFreq>& tfVec
    void selectionSort(std::vector<TokenFreq>& tokFreqVector );
    void insertionSort(std::vector<TokenFreq>& tokFreqVector );
}



#endif                        //End of header guard _TOKEN_FREQ_