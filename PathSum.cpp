//
//  PathSum.cpp
//  leetcode
//
//  Created by witwolf on 4/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//




/**
 * Definition for binary tree
 */



struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};


bool hasPathSum(struct TreeNode *root, int sum) {
    if(!root){
        return false;
    }
    sum -= root->val;
    if(!root->left  && !root->right && sum==0){
        return true;
    }
    if(root->left && hasPathSum(root->left, sum)){
        return true;
    }
    
    if(root->right && hasPathSum(root->right, sum)){
        return true;
    }
    return false;

}
