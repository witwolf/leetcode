//
//  WordDictionary.cpp
//  leetcode
//
//  Created by witwolf on 5/19/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <string>

using namespace std;

struct Node;

struct Node{
    Node(){childs=NULL;}
    Node* childs;
};


class Trie{
public:
    Trie(){
        root = new Node;

    }
    
    void addWord(string word){
        Node *node = root;
        for(char c:word){
            
        }
    }
    
    bool search(string word){
        return false;
    }
    
private:
    Node* root;
    
};


class WordDictionary {
public:
    
    // Adds a word into the data structure.
    void addWord(string word) {

    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return false;
    }
    


};





