//
// //////Created by Khalid Khan on 11/12/23.
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <map>
//#include <sstream>
//#include <set>
//
//using namespace std;
//
//int main() {
//    vector<string> sentences;
//
//
//
//    string filename = "/Users/khalidkhan/Workspace/CPP/speechDetection/SteveJobsSpeech2005.txt";
//
//    ifstream inputFile;
//
//    inputFile.open(filename);
//    // Sentence Splitter ...................
//
//    if (inputFile.is_open()) {
//        string currentSent;
//        string createSent;
//        cout << "File opened successfully." << endl;
//
//        while (getline(inputFile, currentSent)) {
//
//            if (currentSent.length()) {
//                for(int i = 0; i < currentSent.length(); i++) {
//                    char c = currentSent.at(i);
//                    if (c == '.' || c == '?' || c == '!') {
//                        if(i + 1 < currentSent.length() && currentSent.at(i+1)=='"') {
//                            i++;
//                        }
// ////                        createSent += c;
//                        if(createSent.length()) {
//                            sentences.push_back(createSent);
//                            createSent = "";
//                        }
//
//
//                    } else {
//
//                        createSent += c;
//
//
//                    }
//                }
//            }
//
//        }
//
//        inputFile.close();
//    } else {
//        cout << "Failed to open file." << endl;
//        return 1;  // Exit the program with an error code
//    }
//
//    cout<<sentences.size()<<endl;
//    // Sentence Splitter .................. END.
//
// ///////////
//    for (string s : sentences) {
//        cout << s << endl;
//    }
// ////////////
//
//    // Word Pair Mapping ...................
//    map <pair<string,string>, int> wordpairFreq_map;
//    vector <pair<string,string>> tempWordPairs;
//
//    istringstream tempStringStream;
//    string word;
//    set <string> uniqueWords;
//
//
//    vector<set<string>> uniqueSentences;  // Each sentence will have its own set
//

//
//    for (string sentence : sentences) {
//        tempStringStream.str(sentence);
//
//        while (tempStringStream >> word) {
//            if (!word.empty() && word != " " && word != "\n" && word != "\t" && word != "" && word != "—") {
//                char firstChar = word.front();
//
//                // Check if the first character is not an alphabet character
//                if (!isalpha(firstChar)) {
//                    // Remove the first character
//                    word = word.substr(1);
//                }
//
//                char lastLetter = word.back();
//                if (lastLetter == ',' || lastLetter == '-' || lastLetter == ':' || lastLetter == ';') {
//                    word = word.substr(0, word.size() - 1);
//                }
//
//                // Word to lower case
//                for (int i = 0; i < word.length(); i++) {
//                    word[i] = tolower(word[i]);
//                }
//
//                uniqueWords.insert(word);
//            }
//        }
//
//        // Push the uniqueWords set for this sentence into uniqueSentences
//        uniqueSentences.push_back(uniqueWords);
//
//        // Clear uniqueWords for the next sentence
//        uniqueWords.clear();
//
//        tempStringStream.clear();
//    }
//
//
//
//
//
//
//
//    string word1, word2;
//
//    for (auto uniqueSentence : uniqueSentences) {
//        for (auto it = uniqueSentence.begin(); it != uniqueSentence.end(); it++) {
//            word1 = *it;
//            auto it2 = it;
//            it2++;
//            for (; it2 != uniqueSentence.end(); it2++) {
//                word2 = *it2;
//
//                // Check if the pair is already present in the map
//                auto pairFreqIt = wordpairFreq_map.find(make_pair(word1, word2));
//
//                if (pairFreqIt != wordpairFreq_map.end()) {
//                    // If present, increment the frequency
//                    pairFreqIt->second++;
//                } else {
//                    // If not present, add a new entry with a frequency of 1
//                    wordpairFreq_map[make_pair(word1, word2)] = 1;
//                }
//            }
//        }
//    }
//

//    for (const auto& pair : wordpairFreq_map) {
//        cout << "(" << pair.first.first << ", " << pair.first.second << "): " << pair.second << endl;
//    }
//
//
//
//
//
//    // Word Pair Mapping ................... END.
//
//
//
//
//    return 0;
//}
