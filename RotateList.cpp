//
//  RotateList.cpp
//  leetcode
//
//  Created by witwolf on 5/6/15.
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *first = head,*prev = NULL,*second = head;
    while(k--){
        second = second->next;
    }
    
    while(second){
        prev = first;
        first = first->next;
        second = second->next;
    }
    
    return NULL;
}
