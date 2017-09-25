//
//  BinaryTreeRightSideView.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <utility>
#include <deque>
#include <iostream>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        deque<pair<TreeNode*,int> > nodes(1,make_pair(root, 1));
        vector<int> levels(1,1);
        while(!nodes.empty()){
            pair<TreeNode*,int> p = nodes.front();
            nodes.pop_front();
            TreeNode* node = p.first;
            int level = p.second;

            if(!(--levels[level-1] )){
                result.push_back(node->val);
            }
            

            if(levels.size() < level + 1){
                levels.push_back(0);
            }
            if(node->left){
                nodes.push_back(make_pair(node->left, level+1));
                levels[level] ++ ;
            }
            if(node->right){
                nodes.push_back(make_pair(node->right, level+1));
                levels[level] ++ ;
            }
            
        }
        
        return result;
    }
};

int main(int argc,char **argv){
    
    TreeNode node1(1),node2(2),node3(3);
    node1.left = &node2;
    node1.right = &node3;
    Solution s;
    vector<int> r = s.rightSideView(&node1);
    copy(r.begin(),r.end(),ostream_iterator<int>(cout," "));
}
