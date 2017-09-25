//
//  RemoveLinkedListElements.cpp
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
 
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* node = head;
    while (node) {
        if(node->val == val){
            if(prev == NULL){
                head = node->next;
                free( node);
                node = head;
            }else{
                prev->next = node->next;
                free( node);
                node = prev->next;
            }
        }else{
            prev = node;
            node = node->next;
        }
    }
    return head;
}
