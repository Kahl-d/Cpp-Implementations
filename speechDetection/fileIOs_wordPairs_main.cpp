#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fileIOs_wordPairs.h"


int main (){

    std::vector<std::string> sentences;
    std::string filename = "/Users/khalidkhan/Workspace/CPP/speechDetection/SteveJobsSpeech2005.txt";

    sentenceSplitter(filename, sentences);

    std::cout<< sentences.size() << std::endl;
    int i = 0;
    for(auto it = sentences.begin(); it != sentences.end(); it++){
        std::cout<<i << ": ";
        std::cout << *it << std::endl;
        i++;
    }

    std::map<std::pair<std::string,std::string>, int> wordpairFreq_map;

    wordpairMapping(sentences, wordpairFreq_map);

    for(auto it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); it++){

        std::cout << "<" << it->first.first << "," << it->first.second << ">: " << it->second << std::endl;

    }

    return 0;
}