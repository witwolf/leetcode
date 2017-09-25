//
//  SameTree.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>


/**
 * Definition for a binary tree node.
 */

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == q){
        return true;
    }
    if (!p || !q || q->val != p->val){
        return false;
    }
    
    if(!isSameTree(p->left, q->left)){
        return false;
    }
    
    if(!isSameTree(p->right, q->right)){
        return false;
    }
    
    return true;
}