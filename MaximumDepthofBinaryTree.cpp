//
//  MaximumDepthofBinaryTree.cpp
//  leetcode
//
//  Created by witwolf on 6/25/15.
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
 
int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftDepth = 1 + maxDepth(root->left);
    int rightDepth = 1 + maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth : rightDepth;
    
}
