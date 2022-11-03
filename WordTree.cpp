/* 
Name: Sanket Karna
Date: 9th March 2022
File: WordTree.cpp
This file is the implementations of the methods and functions that are defined in the WordTree class in the WordTree.h file
*/
#include "WordTree.h"

/* This method is a 0 arguement construtor for Word Tree
Pre : The root_ object is being instantiated
Post : The root_ object has been created
*/
WordTree::WordTree() {
    root_ = new WordTree::WordNode;
}

/* This method is a destructor of the WordTree object
Function: It calls on a helper method deleteTree() that is recursive to delete the tree
Pre : A WordTree object exists
Post : The WordTreee object has been deleted
*/

WordTree::~WordTree() {
    deleteTree(root_);
}

/* This method adds a word to the WordTree object 
Function: It calls on a helper method addWord() that is recursive to add the tree
Parameters: This funtion takes in a string input. This string is the value that is being added to the tree
Pre : A wordtree has been created
Post : A new word is being added to the WordNode object
*/
void WordTree::add(string input) {
    addWord(input, root_);
}

/* This method adds a word to the WordTree object 
Function: It calls on a helper method addWord() that is recursive to add the tree
Parameters: This funtion takes in a string input. This string is the value that is being added to the tree
Pre : A wordtree has been created
Post : A new word is being added to the WordNode object
*/
int WordTree::numWords() {
    int num;
    num = countWords(root_);
    return num;
}

/* This method is an operator overload of the cout<< to print the tree to the console 
Function: It calls on a helper method printTree() that is recursive to visit each node of the tree
Parameters: It takes in out, the thing that is sent back to the terminal
            The WordTree& that is being printed and being put into out 
Pre : A WordTree refrence exists
Post : WordTree object is printed to the console
*/
ostream& operator<<(ostream& out, WordTree& newTree) {
    
    out << newTree.printTree(newTree.root_); // put the return value of the printTree method in out
    return out; // return out
}

/* This method is a helper method of add, to add a word to the WordTree object recursively
Function: It checks and adds words to the Tree by checking if the words is smaller or greater than the existing word alphabetically
Parameters: Takes the string value that is being added to the Tree and the root* of the tree that it is being added to
Pre : add() is called from the main
Post : A unique word is added to the tree, or an existing word's count goes up
*/
WordTree::WordNode* WordTree::addWord(string value, WordNode* root){
    
    if(root_->value_.empty()) { // if the tree is empty
        root_->value_ = value;
        root_->count_++;
        return nullptr;
    }

    if(root != nullptr) { // if the root isnt a null
        if(value.compare(root->value_) > 0) { // checks if the value is greater alphabetically
            root->right_ = addWord(value, root->right_); // recursive call to the right side if it is greater
            return root;
        } else if(value.compare(root->value_) < 0) { // checks if the value is smaller alphabetically
            root->left_ = addWord(value, root->left_); // recursive call to the left side if it is smaller
            return root;
        } else {
            root->count_++; // if the word is already in the tree then we increse the count of the tree
            return root;
        }
    }

    WordNode* node = new WordNode(value); // when there is a new node to be added, it gets created at that spot
    return node; // end
}

/* This method is a helper method of the ~Destructor, to destroy the WordTree object recursively
Function: It uses the postorder traversal to delete the nodes
Parameters: takes the root of the WordNode object
Pre : Function finished and the use of the existing WordNode obj is done, so the destructor is called
Post : The memory of the WordNode object is cleared up
*/
void WordTree::deleteTree(WordNode* root){
   
   if (root == nullptr) { // if the root is null
      return;
   }

   deleteTree(root->left_); // go left recursively
   deleteTree(root->right_); // go right recursively

   delete root; // delete the root
   return;
}

/* This method is a helper method of the numWord, to count the number of unique words in a tree recursively
Function: It uses the preorder traversal to count the nodes
Parameters: takes the root of the WordNode object
Pre : WordNode object exists
Post : The number of nodes/words in the tree is counted up
Return: Returns the interger value of the total count back to numWords()
*/
int WordTree::countWords(WordNode* root){
   int num = 0; 

   if (root == nullptr) { // base case
      return 0;
   }
   num += root->count_; // count the first node
   num += countWords(root->left_); // recursively go left
   num += countWords(root->right_); // recursively go right

   return num; // return
}

/* This method is a helper method of the ostream output operator overload, to print the nodes in the tree recursively
Function: It uses the inorder traversal to visit each node
Parameters: takes the root of the WordNode object
Pre : WordNode object exists
Post : The string word and the number of times it occured is stored in a string value
Return: Returns the string value that contains the output
*/

string WordTree::printTree(WordNode* root) const{
    string returnVal = ""; // return val

    if(root == nullptr) { // base case
        return returnVal;
    }

    returnVal += printTree(root->left_); // go left recursively
    returnVal += root->value_ + " : " + to_string(root->count_) + "\n"; // get the node information and put in the string
    returnVal += printTree(root->right_); // go right recursively

    return returnVal; // retun the string
}