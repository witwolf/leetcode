//
//  GenerateParentheses.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <string>
#include <deque>

using namespace std;



class Solution {

public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n > 0)
            generateParenthesis(n,"",0,0,result);
        return result;
    }
    
    void generateParenthesis(int n,string s,int l,int r,vector<string> &result ){
        if(l == n){
            result.push_back(s.append(n-r, ')'));
            return;
        }
        generateParenthesis(n,s+'(' ,l+1,r,result);
        if(l > r)
            generateParenthesis(n,s+')',l,r+1,result);
    }
};
