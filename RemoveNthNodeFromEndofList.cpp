//
//  RemoveNthNodeFromEndofList.cpp
//  leetcode
//
//  Created by witwolf on 5/5/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//





/**
 * Definition for singly-linked list.
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(n <= 0 || head == NULL){
        return head;
    }
    struct ListNode *first = head,*second=head,*prev = NULL ;
    while(n && second){
        second = second->next;
        n -- ;
    }
    if(n){
        return head;
    }
    while (second) {
        prev = first;
        first = first->next;
        second = second->next;
    }
    
    if(first == head){
        head = head->next;
    }else{
        prev->next = first->next;
    }
    delete first;
    return head;
}

void print(struct ListNode *head){
    while(head){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc,char **argv){
    struct ListNode n1,n2,n3;
    n1.val = 1;
    n1.next = &n2;
    n2.val = 2;
    n2.next = &n3;
    n3.val = 3;
    n3.next = NULL;
    
    print(&n1);
    
    print(removeNthFromEnd(&n1, 1));
}
