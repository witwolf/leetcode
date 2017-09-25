//
//  RemoveDuplicatesfromSortedList.cpp
//  leetcode
//
//  Created by witwolf on 4/27/15.
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
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next== NULL){
        return head;
    }
    struct ListNode* prev = head,*node = head->next;
    while (node) {
        if(node->val == prev->val){
            prev->next = node->next;
            free(node);
            node = prev->next;
            continue;
        }
        prev = node;
        node = node->next;
    }
    return head;
}