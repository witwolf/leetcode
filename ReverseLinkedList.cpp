//
//  ReverseLinkedList.cpp
//  leetcode
//
//  Created by witwolf on 5/5/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>


/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    struct ListNode* prev = NULL,*cur = head,*next = cur->next;
    while(cur && next){
        cur->next = prev;
        prev = cur;
        cur = next ;
        next = cur->next;
    }
    cur->next = prev;
    return cur;
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
    
    print(reverseList(&n1));
}
