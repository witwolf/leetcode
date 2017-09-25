//
//  SumRoottoLeafNumbers.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumNumbers(struct TreeNode* node,int base){
    if(node == NULL)
        return 0;
    int result = base * 10  + node->val ;
    if(node->left == NULL && node->right == NULL){
        return result;
    }
    return sumNumbers(node->left,result) + sumNumbers(node->right ,result);
}

int sumNumbers(struct TreeNode* root) {
    return sumNumbers(root,0);
}
