//
//  IntersectionofTwoLinkedLists.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
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

int len(struct ListNode *root){
    int length = 0;
    while(root){
        length++;
        root = root->next;
    }
    return length;
}

struct ListNode* forward(struct ListNode * node,int stride){
    while(stride -- ){
        node = node->next;
    }
    return node;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = len(headA);
    int lenB = len(headB);
    if(lenA > lenB){
        headA = forward(headA, lenA - lenB);
    }else if(lenB > lenA){
        headB = forward(headB, lenB - lenA);
    }
    while (headA && headB) {
        if(headA == headB){
            return  headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return headA;
}
