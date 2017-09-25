//
//  AddTwoNumbers.cpp
//  leetcode
//
//  Created by witwolf on 5/5/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* node,*prev = NULL,*head = NULL;
    int val = 0;
    while(l1 || l2 || val){
        if(l1){
            val += l1->val;
            l1 = l1->next;
        }
        if(l2){
            val += l2->val;
            l2 = l2->next;
        }
        node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = val % 10;
        val = val / 10 ;
        if(head == NULL){
            head = node ;
            prev = node;
        }else{
            prev->next = node;
            prev = node ;
        }
    }
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
    n1.val = 9;
    n1.next = &n2;
    n2.val = 8;
    n2.next = &n3;
    n3.val = 5;
    n3.next = NULL;
    
    print(&n1);
    
    print(addTwoNumbers(&n1,NULL));
    print(addTwoNumbers(NULL,NULL));
    print(addTwoNumbers(&n1,&n1));
}