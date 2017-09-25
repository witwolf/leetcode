//
//  ValidParentheses.cpp
//  leetcode
//
//  Created by witwolf on 5/5/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//


#include <iostream>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
    
    // 123 {
    // 125 }
    // 91 [
    // 93 ]
    // 40 (
    // 41 )
    
    bool isValid(string s) {
        stack<char> chars;
        chars.push(0);
        for(auto c:s){
            int diff = c - chars.top();
            if(diff == 1 || diff == 2){
                chars.pop();
            }else{
                chars.push(c);
            }
        }
        return chars.size() == 1;
    }

};


int main(int argc,char **argv) {
    Solution s;
    cout << s.isValid("()") << endl;
    
}
