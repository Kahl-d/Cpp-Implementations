//
// Created by Khalid Khan on 11/12/23.
// CPP file for fileIOs_wordPairs.h
// Contains function definitons for
//    1. Sentence Splitter
//    2. Word Pair Mapping
//    3. Flip Map
//    4. Print Function, most and least frequent word-pairs

#include <iostream>
#include "fileIOs_wordPairs.h"

// Sentence Splitter Fucntion definiton
// Splits sentence based on the following delimiters: . ? ! \n
// updates the sentences vector with the split sentences

void sentenceSplitter(std::string &fname, std::vector<std::string> &sentences) {
    sentences.clear();
    // Initialize and Open file with the given name
    std::ifstream inputFile(fname);

    if (inputFile.is_open()) {
        std::string currentLine;
        std::string createSentence;
        char c;

        // Read the file line by line
        while(getline(inputFile, currentLine)){

            // for each line, read the characters one by one
            for(size_t i =0; i< currentLine.length(); i++){
                c = currentLine.at(i);

                // if the character is not a delimiter, add it to the sentence
                if(c != '.' && c != '?' && c != '!' && c != '\n' ) {
                    createSentence += c;
                }

                    // if the character is a delimiter, add the sentence to the sentences vector
                else
                {
                    //only if the sentence is not empty, add it to the vector
                    if (!createSentence.empty()) {

                        //remove beginning spaces if in a sentence
                        while (createSentence.at(0) == ' ') {
                            createSentence.erase(0, 1);
                        }

                        // add the sentence to the vector
                        sentences.push_back(createSentence);
                        createSentence = "";
                    }
                    //checking for cases ." and ?"
                    if( i+1 < currentLine.length() && currentLine.at(i+1)=='"'){
                        //skip the "
                        i++;
                    }


                }
            }
            if (!createSentence.empty()) {
                while (createSentence.at(0) == ' ') {
                    createSentence.erase(0, 1);
                }
                sentences.push_back(createSentence);
                createSentence = "";
            }
        }


        inputFile.close();
    } else {
        std::cerr << "Failed to open file: " << fname << std::endl;
    }
}


// Sentence Splitter .................. END.

//Helper Function to convert words to lower case

std::string toLowerCase(const std::string &word) {
    std::string result = word;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// ///////////
// Word Pairing Section
// Function to create word pairs of the sentences
// Updates the wordpairFreq_map with the word pairs and their frequencies
// freq of a word pair if the number of setnences the word pair is present in
// every presence will be counted as one no matte how many times a word pair is in a particular sentence

void wordpairMapping(std::vector<std::string> &sentences, std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map) {

    //temporary variables to move values around
    std::istringstream tempStringStream;
    std::string word;
    std::set<std::string> uniqueWords;
    std::vector<std::set<std::string>> uniquePairs;


    // Loop through each sentence, and take a word as input
    for (const std::string& sentence : sentences) {
        tempStringStream.str(sentence);

        // Loop through each word in the sentence
        while (tempStringStream >> word) {
            // If the word is not empty, add it to the set
            if (!word.empty()) {
                // Convert the word to lower case
                word = toLowerCase(word);

                uniqueWords.insert(word);
            }
        }

        // Push the uniqueWords set for this sentence into uniqueSentences
        uniquePairs.push_back(uniqueWords);

        // Clear uniqueWords and strinf stream for the next sentence
        uniqueWords.clear();
        tempStringStream.clear();
    }

    // Pairing the words

    std::string word1;
    std::string word2;

    // Loop through each set of unique words to create pair
    // as we are using a set, the words will be in alphabetical order and no duplicates

    for (auto uniqueSentence: uniquePairs) {

        // a pointer to the beginning of the set
        auto startIterator = uniqueSentence.begin();


        for(; startIterator != uniqueSentence.end()-- ;startIterator++){

            // first word of the pair would be the current word
            word1 = *startIterator;
            auto secondIterator = startIterator;

            secondIterator++;
            for (; secondIterator != uniqueSentence.end(); secondIterator++) {

                // second word of the pair would be the next word
                word2 = *secondIterator;

                // Check if the pair is present in the map
                auto pairFreqIt = wordpairFreq_map.find(make_pair(word1, word2));

                if (pairFreqIt != wordpairFreq_map.end()) {
                    // If present, increment the frequency
                    pairFreqIt->second++;
                } else {
                    // If not present, add a new entry with a frequency of 1
                    wordpairFreq_map[make_pair(word1, word2)] = 1;
                }
            }
        }
    }


}

// Other Functions

//    3. FLIP MAP

// flip the map of to a multimap of to order all the word-pairs in ascending order of frequency
// frequencies will be the keys and word-pairs will be the values
// multimap will be needed as two word-pairs can have the same frequency

void freqWordpairMmap(std::map < std::pair < std::string, std::string >, int > &wordpairFreq_map,
                      std::multimap< int, std::pair < std::string, std::string > > &freqWordpair_mmap)

{
    //Loop through the map and insert the values into the multimap
    for(auto wPair : wordpairFreq_map){

        //make a reverse pair of the word pair
        //insert the reverse pair into the multimap
        freqWordpair_mmap.insert(std::make_pair(wPair.second, wPair.first));
    }



}

//    4. PRINT Function
// output the most frequent and least frequent word-pairs to a file
// writes the top topCnt most frequent word-pairs and botCnt least frequent word-pairs to a file of the name outFname
// use multimap's iterator and revserse_iterator to access the most frequent and least frequent word-pairs
// output will be one word-pair per line in the format of <word1, word2>: frequency }

void printWordpairs(std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_multimap,
                    std::string outFname, int topCnt, int botCnt){

    std::ofstream outputFile(outFname);

    if(!outputFile.is_open()){
        std::cerr << "Failed to open file: " << outFname << std::endl;
    }
    else{
        //Pointer to the beginning and end of the multimap
        auto startIterator = freqWordpair_multimap.begin();

        //Pointer to the end of the multimap
        auto endIterator = freqWordpair_multimap.end();

        for(int i{topCnt}; i > 0; i--){
            outputFile << "<" << startIterator->second.first << ", " << startIterator->second.second << ">: " << startIterator->first << std::endl;
            startIterator++;
        }

        for(int i{botCnt}; i > 0; i--){

            outputFile << "<" << endIterator->second.first << ", " << endIterator->second.second << ">: " << endIterator->first << std::endl;
            endIterator--;
        }

        outputFile.close();

    }


}

