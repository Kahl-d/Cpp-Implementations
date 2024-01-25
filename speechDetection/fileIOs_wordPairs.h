//
// Created by Khalid Khan on 11/12/23.
//

// Khalid Mehtab Khan
// 11/12/23
// Small Group Project 2 CSC 340
// Contains functions definitions for
//    1. Sentence Splitter
//    2. Word Pair Mapping
//    3. Flip Map
//    4. Print Function, most and least frequent word-pairs





#ifndef FILEIOS_WORDPAIRS_H
#define FILEIOS_WORDPAIRS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>



// converts a text file with the name fname into a list of sentences
// list of sentences are stored in the sentences vector in order
// Splits sentence based on the following delimiters: . ? ! \n
// updates the sentences vector with the split sentences

void sentenceSplitter(std::string &fname, std::vector<std::string> &sentences);

// Function to create word pairs of the sentences
// Updates the wordpairFreq_map with the word pairs and their frequencies
// freq of a word pair if the number of setnences the word pair is present in
// every presence will be counted as one no matte how many times a word pair is in a particular sentence

void wordpairMapping(std::vector<std::string> &sentences,
                     std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map);

// flip the map of to a multimap of to order all the word-pairs in ascending order of frequency // frequencies will be the keys and word-pairs will be the values
// multimap will be needed as two word-pairs can have the same frequency
void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map,
                      std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_mmap);

// output the most frequent and least frequent word-pairs to a file
// writes the top topCnt most frequent word-pairs and botCnt least frequent word-pairs to a file of the name outFname
// use multimap's iterator and revserse_iterator to access the most frequent and least frequent word-pairs
// output will be one word-pair per line in the format of <word1, word2>: frequency }

void printWordpairs(std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_multimap,
                    std::string outFname, int topCnt, int botCnt);



#endif
