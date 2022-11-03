/* 
Name: Sanket Karna
Date: 9th March 2022
File: CountWord.cpp
This file contains a main() method. This main method asks the user to input a stream of words into the terminal. Either by typing it in or through a file
Then it fiters the things typed in by word. and adds it into the WordTree which is a BST.
*/
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.h"

using namespace std;

/* This function is the main fucntion that asks the user for input, creates a WordTree BSt and outputs that into the console or into whatever the user would like to redirect it to
The input for this can be anything, however, the only thing that is going to get added into the tree is a word. The classification for a word in this function is as follows. 
We can assume that a word with apostrophe in the middle “don’t” is a whole word while words like “students’” with an apostrophe at the end is also a word without the apostrophe. 
Mostly, words will be separated by blank spaces, but not all the time. Words like “best-selling” is not separated by a blank space but is still two words “best”  and “selling". 
We can assume numbers like 2 or 2/3 aren’t a word. 

This gets put into a BST alphabetically and when printed, it is done so alphabetically.
If there are multiple of the same word, it will not be added because the BST is full of unique words.
However, the count for that existing word will go up.

*/
int main() {

    WordTree newBST; // BST object 
    char in; // input variable
    string word; // word varibale to add into the tree

    cout << "Enter your words that you want in the tree" << endl;

    while(cin.get(in)) { // cin.get() funtion to read the stream of input by the user character by character 
        in = tolower(in); // lowers each input

        if(isalpha(in) || in == 39) { // Any character that isnt a letter or an apostrophe (39 is the ASCII value for ') will not be added to the word
            word.push_back(in); // keep adding onto to the word using push_back()
        } else { // once we hit a unwanted input we stop adding to the word
            if(word.size() != 0) { // check to see no blank spaces are being put into the tree
                if(word.back() == 39) { // check to see if the back of the word as an apostrophe ( cant have students')
                    word.pop_back(); // if it does delete it
                } else if(word.front() == 39) { // check to see if the front of the word as an apostrophe ( cant have 'students)
                    word = word.substr(1, word.length() -1 ); // if it does delte it by taking the substring
                }
                if(word.size() == 1) { // if the word cannot be a single letter
                    word.clear(); // clear it for the next valid letter
                }
                else { // once all edge cases are checked
                    newBST.add(word); // add the word
                    word.clear(); // clear it for the next valid letter
                }

            }
        }
    }

    cout << "Total words number of unqiue words in the tree: " << newBST.numWords() << endl; // total output of unique words in the tree
    cout << newBST << endl; // printing the entire tree
    
    return 0;
}