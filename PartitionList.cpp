//
//  PartitionList.cpp
//  leetcode
//
//  Created by witwolf on 4/24/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
      int val;
      struct ListNode *next;
};


struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* prev = NULL,*node = head,*guaid = NULL,*guaid_prev = NULL,*next=NULL;
    while (node) {
        next = node->next;
        if(guaid != NULL && node->val < x){
            if(guaid == head){
                head = node;
                head->next = guaid;
                guaid_prev = head;
            }else{
                guaid_prev->next = node;
                guaid_prev = node;
                guaid_prev->next = guaid;
            }
            if(prev){
                prev->next = next;
            }
            node = next;
            continue;
        }
        
        if(guaid == NULL && node->val >= x){
            guaid_prev = prev;
            guaid = node;
        }
        prev = node;
        node = next;
    }
    return head;
}


