//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.

//Please make sure that you include the entire content of this file as comments.

/* Design Doc: communicate your thought process in English.
 
0. List of members who contributed to the implementation of this project:
   Small Group - 3
   Khalid Mehtab Khan
   Jaylene Acosta
   Diya Tamrakar
 
1. Describe your algorithm for the sentenceSplitter( ) function in pseudocode.
   

   - Input: 
      - 'fname' (Type: String) - The file name or path
      - 'sentences' (Type: List) - Container for storing sentences
      
   - Output: 
      - Update the 'sentences' list with sentences from the file.

Step 1:
      - Open the file specified by 'fname'.
      - If (successful) : 
            proceed to the next step (Step 2). 
            
      - If (unsuccessful)
            print an error message and exit.

Step 2: 
         - for : every line in the file
         
                currentLine <== line
               
            - While 'currentLine' is not empty:
               - For each character 'c' in 'currentLine':
               
                  - If 'c' is not a sentence delimiter ('.', '?', '!', or '\n'):
                     - Append 'c' to `createSentence`.
                     
                  - Else:
               
                     - If 'createSentence' is not empty:
                        - Remove leading spaces
                        - add 'createSentence' to 'sentences'
                        - reset 'createSentence'.
                        
                     // to work the ?" and ." case
                     - If the next inbounds character is '"'
                        - Skip the double quote by incrementing 'i'.

Step 3: 
         - If 'createSentence' is not empty:
            - Remove leading spaces
            - add it to 'sentences'
            - reset 'createSentence'.
            
         - Read the next line from the file and update `currentLine`.

Step 4:  - Close the file.

Complexity Analysis: # of lines in the file = n
                     # number of charcter in the longest line = m;
            
            1 - Opening and closing the file: O(1) (constant time).
            2 - Iterating through each line (n lines): O(n).
            3 - Iterating through each character in a line (m characters): O(m).
            4- Processing each character: O(1) (each character is processed in constant time).
            
            Overall time complexity: O(n * m) = O (k2)
            
            




2. Describe your algorithm for the wordpairMapping( ) function in pseudocode.

 Input:
      1) sentences         - List of sentences
      2) wordpairFreq_map  - Container for storing word pairs and their frequencies

Output:
      - Update the wordpairFreq_map with word pairs and their frequencies.


Algorithm Steps:


Step 1: for each (sentence in sentences):

             for each (word in sentence):
               If word: not empty
                  - convert it to lowercase 
                  - insert it into the uniqueWords set.
                  
         - Push the uniqueWords set for this sentence into uniquePairs.
         - Clear uniqueWords and reset tempStringStream for the next sentence.

Step 2: Pairing the words:
            for each (set in uniquePairs)
               make pair ( wordi, wordj).    [ i != j ]
               Check if the pair (word1, word2) is present in wordpairFreq_map.
               If : present
                  increment the frequency.
               If : not present
                  add a new entry with a frequency of 1.
                  
2. Complexity Analysis:

   - Looping through each sentence (n sentences): O(n).
   - Looping through each word in a sentence (m words): O(m).
   - Pairing unique words and updating the frequency: O(n * m^2) (nested loops for each unique word in each sentence).
   
   Overall time complexity: O(n * m^2) = O (k3);

*/