//
//  BalancedBinaryTree.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

/**
 * Definition for a binary tree node.
 */

#include <stdlib.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

bool isBalancedTree(struct TreeNode* node,int *height){
    if(node == NULL){
        *height = 0;
        return true;
    }
    int leftHeight = 0 ;
    int rightHeight = 0;
    if(!isBalancedTree(node->left, &leftHeight)){
        return false;
    }
    if(!isBalancedTree(node->right, &rightHeight)){
        return false;
    }
    if(abs(leftHeight - rightHeight) > 1){
        return false;
    }
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    return true;
}

bool isBalanced(struct TreeNode* root) {
    int heigit = 0;
    return isBalancedTree(root, &heigit);
}
