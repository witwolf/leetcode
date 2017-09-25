//
//  CopyListwithRandomPointer.cpp
//  leetcode
//
//  Created by witwolf on 7/25/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        RandomListNode *p = head;
        vector<RandomListNode*> nodes;
        map<RandomListNode*,int> nodePos;
        int pos = 0;
        while(p){
            nodes.push_back(p);
            nodePos[p] = pos++;
            p = p->next;
        }
        vector<int> randomPos ;
        p = head;
        while(p){
            if(p->random){
                randomPos.push_back(nodePos[p->random]);
            }else{
                randomPos.push_back(-1);
            }
            p = p->next;
        }
        
        vector<RandomListNode*> newNodes;
        p = head;
        while(p){
            newNodes.push_back(new RandomListNode(p->label));
            p = p->next;
        }
        newNodes.push_back(NULL);
        for(pos = 0 ; pos < newNodes.size() - 1 ; pos++){
            newNodes[pos]->next = newNodes[pos+1];
            if(randomPos[pos] != -1){
                newNodes[pos]->random = newNodes[randomPos[pos]];
            }
        }
        return newNodes[0];
    }
};
