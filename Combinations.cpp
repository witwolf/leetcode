//
//  Combinations.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine(1, n, k, vector<int>());
    }
    
    vector<vector<int> > combine(int from,int to,int k,vector<int> prefix){
        vector<vector<int> > result;
        if(k == 0){
            if(prefix.size() > 0)
                result.push_back(prefix);
            return result;
        }
        // 减枝
        if(to - from + 1 == k){
            for(int i = from ; i <= to ; ++i){
                prefix.push_back(i);
            }
            result.push_back(prefix);
            return result;
        }
        if(to - from + 1 < k){
            return result;
        }
        vector<vector<int> > r1 = combine(from+1, to,k,prefix);
        for(vector<vector<int> >::iterator it=r1.begin();it!=r1.end();++it){
            result.push_back(*it);
        }
        
        prefix.push_back(from);
        vector<vector<int> >r2 = combine(from+1, to, k-1, prefix);
        for(vector<vector<int> >::iterator it=r2.begin();it!=r2.end();++it){
            result.push_back(*it);
        }
        
        return result;
    }
};
