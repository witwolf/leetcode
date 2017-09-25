//
//  RemoveDuplicatesfromSortedListII.cpp
//  leetcode
//
//  Created by witwolf on 4/25/15.
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

void freeRange(struct ListNode* from,struct ListNode* to){
    struct ListNode* node ;
    while (from != to) {
        node = from;
        from = from->next;
        free(node);
    }
}
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* start_prev = NULL,*start=head,*end = NULL,*node = head;
    while (node) {
        if(node->val != start->val){
            // 删除 [start,end]
            if(start != end && end != NULL){
                if(start == head){
                    head = node;
                }else{
                    start_prev->next = node;
                }
                freeRange(start, node);
            }else{
                start_prev = start;
            }
            end = NULL;
            start = node;
        }else{
            end = node;
        }
        node = node->next;
    }
    if(start != end && end!= NULL){
        freeRange(start,NULL);
        if(start_prev){
            start_prev->next = NULL;
        }else{
            return NULL;
        }
    }
    return head;
}