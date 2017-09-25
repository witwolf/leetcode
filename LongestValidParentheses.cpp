//
//  LongestValidParentheses.cpp
//  leetcode
//
//  Created by witwolf on 5/6/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//


#include <string>
#include <stack>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxLength = 0;
        int length = 0;
        stack<pair<char,int> > stk;
        stk.push(make_pair('#', -1));
        for(int i = 0 ; i < s.length() ; ++i){
            pair<char,int> top = stk.top();
            if(s[i] - top.first == 1){
                stk.pop();
                length = i - stk.top().second;
                if(length > maxLength){
                    maxLength = length;
                }
                
            }else{
                stk.push(make_pair(s[i],i));
            }
        }
        return maxLength;
    }
};

int main(int argc,char **argv){
    Solution s;
    while(true){
        string ss;
        cin >> ss;
        cout << ss << ":" << s.longestValidParentheses(ss) << endl;
    }
}