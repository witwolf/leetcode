//
//  LRUCache.cpp
//  leetcode
//
//  Created by witwolf on 3/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <list>
#include <map>
#include <utility>


using namespace std;


struct Node{
    Node(int v){
        value = v;
        prev = next = NULL;
    }
    int value;
    Node * prev;
    Node * next;
} ;

class DoubleLinkList{
public:
    DoubleLinkList(int capacity):head(NULL),tail(NULL),_capacity(capacity),_size(0){}
    
    int size(){
        return _size;
    }
    
    Node * front(){
        return head;
    }
    
    void pop_front(){
        this->erase(head);
    }
    
    void erase(Node *node){
        Node* prev = node->prev;
        Node* next = node->next;
        if(prev){
            prev->next = next;
        }else{
            head = next;
        }
        if(next){
            next->prev = prev;
        }else{
            tail = prev;
        }
        _size -= 1;
        delete node;
    }
    
    Node * push_back(int value){
        Node * node = new Node(value);
        if(tail == NULL){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        _size += 1;
        return node;
    }
    
private:
    int _size;
    int _capacity;
    Node* head;
    Node* tail;
};

class LRUCache{
public:
    LRUCache(int capacity):keys(capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = kv.find(key);
        if (it != kv.end()){
            keys.erase(it->second.second);
            it->second.second = keys.push_back(key);
            return it->second.first;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = kv.find(key);
        if(it != kv.end()){
            keys.erase(it->second.second);
            it->second.second = keys.push_back(key);
            it->second.first = value;
        }else{
            if(keys.size() == capacity){
                kv.erase(keys.front()->value);
                keys.pop_front();
            }
            Node * node = keys.push_back(key);
            kv[key] = make_pair(value, node);
        }
    }
    
private:
    map<int,pair<int,Node*> > kv;
    DoubleLinkList keys;
    int capacity;
};

int main(int argc,char **argv){
    
    DoubleLinkList dll(10);
    Node * node1 = dll.push_back(5);
    Node * node2 = dll.push_back(2);
    Node * node3 = dll.push_back(2);
    Node * node4 = dll.push_back(2);
    Node * node5 = dll.push_back(2);
    Node * node6 = dll.push_back(2);
    Node * node7 = dll.push_back(2);
    dll.erase(node2);
    dll.erase(node5);
    dll.pop_front();
    dll.erase(node7);
    dll.erase(node4);
    
    LRUCache lru(2);
    lru.get(2);
    lru.set(2,6);
    lru.get(1);
    lru.set(1,5);
    lru.set(1,2);
    lru.get(1);
    lru.get(2);
}