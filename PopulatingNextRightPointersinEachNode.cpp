//
//  PopulatingNextRightPointersinEachNode.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <deque> 
#include <utility>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }
        deque<pair<TreeLinkNode*,int>> nodes(1,make_pair(root, 1));
        while(!nodes.empty()){
            pair<TreeLinkNode*,int> p = nodes.front();
            nodes.pop_front();
            TreeLinkNode* node = p.first;
            int level = p.second + 1;
            if(node->left){
                if(!nodes.empty() && nodes.back().second == level){
                    nodes.back().first->next = node->left;
                }
                nodes.push_back(make_pair(node->left, level));
            }
            if(node->right){
                if(!nodes.empty() && nodes.back().second == level){
                    nodes.back().first->next = node->right;
                }
                nodes.push_back(make_pair(node->right, level));
            }
        }
        
    }
};
