//
//  MinimumWindowSubstring.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.empty() || t.empty()){
            return "";
        }
        char appeared[256] = {0};
        char expected[256] = {0};
        for(int i = 0 ; i < s.size(); ++i){
            appeared[s[i]] = 1;
        }
    
        int minStart = 0 , minWidth = 2147483647;
        
        
        
        return s.substr(0,1);
        
    }
};
