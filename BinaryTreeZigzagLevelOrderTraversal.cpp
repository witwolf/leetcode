//
//  BinaryTreeZigzagLevelOrderTraversal.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <deque>
#include <utility>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        deque<pair<TreeNode*,int>> nodes(1,make_pair(root,1));
        while(!nodes.empty()){
            pair<TreeNode*,int>  p = nodes.front();
            nodes.pop_front();
            TreeNode *node = p.first;
            int level = p.second;
            if(result.size() < level){
                result.push_back(vector<int>(1,node->val));
            }else{
                result.back().push_back(node->val);
            }
            if(node->left){
                nodes.push_back(make_pair(node->left,level+1));
            }
            if(node->right){
                nodes.push_back(make_pair(node->right,level+1));
            }
        }
        for(int i = 1; i < result.size() ; i = i +2){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
