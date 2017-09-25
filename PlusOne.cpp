//
//  PlusOne.cpp
//  leetcode
//
//  Created by witwolf on 4/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(auto it=digits.rbegin();it!=digits.rend();++it){
            *it += c;
            if(*it != 10){
                c = 0;
                break;
            }else{
                *it = 0;
            }
        }
        if(c != 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
