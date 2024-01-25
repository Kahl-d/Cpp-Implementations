// Khalid M Khan
// 11/13/23
// The file contains all the unit test cases for the project
// Units tests for 
//    1. Sentence Splitter
//    2. Word Pair Mapping
//    3. Flip Map
//    4. Print Function, most and least frequent word-pairs



#include <iostream>
#include "fileIOs_wordPairs.h"
#include <string>
#include <vector>
#include <fstream>  // Added for ifstream
#include <map>

// Function Prototypes for unit tests

// Sentece Splitter
bool test1_SentenceSplitter();
bool test2_SentenceSplitter();
bool test3_SentenceSplitter();

// Word Pairing
bool test1_WordpairMapping();
bool test2_WordpairMapping();
bool test3_WordpairMapping();

// Map Flip to Multimap
bool test1_FreqWordpairMmap();


int main() {
   

    // calling test sentenceSplitter
    std::cout << "Tests for sentence Splitter" <<std::endl;
    std::cout<< "Test 1: ";
    if(test1_SentenceSplitter()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }

    std::cout<< "Test 2: ";
    if(test2_SentenceSplitter()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }

    std::cout<< "Test 3: ";
    if(test3_SentenceSplitter()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }





    // calling test WordpairMapping
    std::cout << "Tests for Wordpair Mapping" <<std::endl;
    std::cout<< "Test1: ";
    if(test1_WordpairMapping()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }

    std::cout<< "Test2: ";
    if(test2_WordpairMapping()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }

    std::cout<< "Test3: ";
    if(test3_WordpairMapping()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }



    // Testing Map Flip function


    // calling test WordpairMapping
    std::cout << "Tests for Map Flip Mapping" <<std::endl;
    std::cout<< "Test1: ";
    if(test1_FreqWordpairMmap()){
      std::cout << "Passed" << std::endl;
    }else{
     std::cout<<"Failed" << std::endl;
    }



    return 0;

//     // inputFile.close();  // This line is unreachable due to the return statement before it
}

bool test1_SentenceSplitter() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";

    inputFile.open(fname);
    
    sentenceSplitter(fname, sentences);

    return true == (sentences.size() == 148);
}

bool test2_SentenceSplitter() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";

    inputFile.open(fname);
    
    sentenceSplitter(fname, sentences);

    return true == (sentences.at(0) == "I am honored to be with you today at your commencement from one of the finest universities in the world");
}

bool test3_SentenceSplitter() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";

    inputFile.open(fname);
    
    sentenceSplitter(fname, sentences);

    return true == (sentences.at(147) == "Thank you all very much");
}


// Tests for word pair mapping
bool test1_WordpairMapping() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";
   
    inputFile.open(fname);
    
    sentenceSplitter(fname, sentences);
    wordpairMapping(sentences, wordpairFreq_map);
    auto pairFreqIt = wordpairFreq_map.find(std::make_pair("i","was"));



    return true == (pairFreqIt != wordpairFreq_map.end()); 
}

bool test2_WordpairMapping() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";

    inputFile.open(fname);
    sentenceSplitter(fname, sentences);
    wordpairMapping(sentences, wordpairFreq_map);
    auto pairFreqIt = wordpairFreq_map.find(std::make_pair("i","was"));



    return true == (pairFreqIt->second == 27); 
}

bool test3_WordpairMapping() {
    std::ifstream inputFile;
    std::vector<std::string> sentences;
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    
    std::string fname = "SteveJobsSpeech2005.txt";

    inputFile.open(fname);
    sentenceSplitter(fname, sentences);
    wordpairMapping(sentences, wordpairFreq_map);
    auto pairFreqIt = wordpairFreq_map.find(std::make_pair("and","believe"));



    return true == (pairFreqIt->second == 1); 
}

bool test1_FreqWordpairMmap() {
      
      std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
      std::multimap<int, std::pair<std::string, std::string>> freqWordpair_multimap;
         
      wordpairFreq_map[std::make_pair("A", "B")] = 5;
      wordpairFreq_map[std::make_pair("C", "D")] = 4;
      wordpairFreq_map[std::make_pair("E", "F")] = 3;
      wordpairFreq_map[std::make_pair("G", "H")] = 2;
      wordpairFreq_map[std::make_pair("I", "J")] = 1;
      
      freqWordpairMmap(wordpairFreq_map, freqWordpair_multimap);
      
      return true == (freqWordpair_multimap.size() == 5);
       
}






