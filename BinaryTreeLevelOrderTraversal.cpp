//
//  BinaryTreeLevelOrderTraversal.cpp
//  leetcode
//
//  Created by witwolf on 4/23/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;



struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        deque<pair<TreeNode*,int> > queue;
        queue.push_back(make_pair(root, 1));
        vector<vector<int> > result;
        while (queue.size()) {
            pair<TreeNode*,int> p = queue.front();
            TreeNode* node = p.first;
            int level = p.second;
            if(node){
                if (result.size() < level){
                    result.push_back(vector<int>());
                }
                result.back().push_back(node->val);
                if(node->left){
                    queue.push_back(make_pair(node->left, level+1));
                }
                if(node->right){
                    queue.push_back(make_pair(node->right, level+1));
                }
            }
            queue.pop_front();
            
        }
        return result;
    }
};

int main(int argc,char **argv){
    
    
}
