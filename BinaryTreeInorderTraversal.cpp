//
//  BinaryTreeInorderTraversal.cpp
//  leetcode
//
//  Created by witwolf on 4/25/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>

using namespace std;



/**
 * Definition for binary tree
 */


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        stack<pair<TreeNode*,char> > queue;
        queue.push(make_pair(root, 1));
        while (queue.size()) {
            pair<TreeNode*, char>& p = queue.top();
            queue.pop();
            TreeNode* node = p.first;
            if(p.second == 0){
                result.push_back(node->val);
            }else{
                if(node->right){
                    queue.push(make_pair(node->right, 1));
                }
                queue.push(make_pair(node, 0));
                if(node->left){
                    queue.push(make_pair(node->left, 1));
                }
            }
        }
        return result;
    }
};
