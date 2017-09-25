//
//  ImplementTrie.cpp
//  leetcode
//
//  Created by witwolf on 5/8/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        
    }

private:
    TrieNode* nexts[26];
    bool end;
    char val;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        return false;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return false;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
