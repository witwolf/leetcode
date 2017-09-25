//
//  SwapNodesInPairs.cpp
//  leetcode
//
//  Created by witwolf on 4/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

/**
 * Definition for singly-linked list.
 */

 struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* p = head, *q = NULL;
    struct ListNode* prev = NULL,*next = NULL;
    while(p && p->next){
        q = p->next;
        next = q->next;
        p->next = next;
        q->next = p;
        if(prev == NULL){
            head = q;
        }else{
            prev->next = q;
        }
        prev = p;
        p = next;
    }
    return head;

}
