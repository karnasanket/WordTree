/* 
Name: Sanket Karna
Date: 9th March 2022
File: WordTree.cpp
This file inlclued the class definitions of the WordTree methods and functions. It also consists of struct of WordNode that holds the Node pointers for the WordTree
WordTree is a BST object that has left_ and a right_ child.
The root_ of the BST WordNode is the parent of left_ and the right_.
*/
#pragma once
#include <iostream>
#include <string>

using namespace std;

class WordTree {
    private:

        /*
        WordNode is s struct inside of WordTree. It consist of a left_ and right_ pointer of the WordTree object.
        Alongside that, it has a value_ that stores the value of the node, and count that store the count (the number of times same word appears)
        All the variables and the methods in struct are public
        */
        struct WordNode {

            string value_; // value of the node
            int count_; // count of the node
            WordNode* left_; // left child of the node
            WordNode* right_; // right child of the node
            
            WordNode(): count_(0), left_(nullptr), right_(nullptr) {} // 0 arguement initialization construtor
            WordNode(string word) : value_(word), count_(1), left_(nullptr), right_(nullptr) {} // 1 argument initialization construtor
        };

        WordNode* root_;

        /* This method is a helper method of add, to add a word to the WordTree object recursively
        Function: It checks and adds words to the Tree by checking if the words is smaller or greater than the existing word alphabetically
        Parameters: Takes the string value that is being added to the Tree and the root* of the tree that it is being added to
        Pre : add() is called from the main
        Post : A unique word is added to the tree, or an existing word's count goes up
        */
        WordNode* addWord(string value, WordNode* root);
        
        /* This method is a helper method of the ~Destructor, to destroy the WordTree object recursively
        Function: It uses the postorder traversal to delete the nodes
        Parameters: takes the root of the WordNode object
        Pre : Function finished and the use of the existing WordNode obj is done, so the destructor is called
        Post : The memory of the WordNode object is cleared up
        */           
        void deleteTree(WordNode* root);
        
        /* This method is a helper method of the numWord, to count the number of unique words in a tree recursively
        Function: It uses the preorder traversal to count the nodes
        Parameters: takes the root of the WordNode object
        Pre : WordNode object exists
        Post : The number of nodes/words in the tree is counted up
        Return: Returns the interger value of the total count back to numWords()
        */        
        int countWords(WordNode* root);
        
        /* This method is a helper method of the ostream output operator overload, to print the nodes in the tree recursively
        Function: It uses the inorder traversal to visit each node
        Parameters: takes the root of the WordNode object
        Pre : WordNode object exists
        Post : The string word and the number of times it occured is stored in a string value
        Return: Returns the string value that contains the output
        */
        string printTree(WordNode* root) const;
    
    public:
        /* This method is a 0 arguement construtor for Word Tree
        Pre : The root_ object is being instantiated
        Post : The root_ object has been created
        */        
        WordTree();

        /* This method is a destructor of the WordTree object
        Function: It calls on a helper method deleteTree() that is recursive to delete the tree
        Pre : A WordTree object exists
        Post : The WordTreee object has been deleted
        */  
        ~WordTree();

        /* This method adds a word to the WordTree object 
        Function: It calls on a helper method addWord() that is recursive to add the tree
        Parameters: This funtion takes in a string input. This string is the value that is being added to the tree
        Pre : A wordtree has been created
        Post : A new word is being added to the WordNode object
        */        
        void add(string input);

        /* This method adds a word to the WordTree object 
        Function: It calls on a helper method addWord() that is recursive to add the tree
        Parameters: This funtion takes in a string input. This string is the value that is being added to the tree
        Pre : A wordtree has been created
        Post : A new word is being added to the WordNode object
        */        
        int numWords();

        /* This method is an operator overload of the cout<< to print the tree to the console 
        Function: It calls on a helper method printTree() that is recursive to visit each node of the tree
        Parameters: It takes in out, the thing that is sent back to the terminal
                    The WordTree& that is being printed and being put into out 
        Pre : A WordTree refrence exists
        Post : WordTree object is printed to the console
        */        
        friend ostream& operator<<(ostream& out, WordTree& newTree);
};
