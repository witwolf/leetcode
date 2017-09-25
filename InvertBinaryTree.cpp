//
//  InvertBinaryTree.cpp
//  leetcode
//
//  Created by witwolf on 6/19/15.
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


struct TreeNode* invertTree(struct TreeNode* root) {
    if(root != NULL){
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}
