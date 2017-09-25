//
//  LongestIncreasingSubsequence.cpp
//  leetcode
//
//  Created by YingXiang Hong on 11/13/15.
//  Copyright © 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS(nums.begin(),nums.end(),numeric_limits<long>::min());
    }

private:
    int lengthOfLIS(vector<int>::iterator begin,vector<int>::iterator end,long min){
        if(begin == end){
            return 0;
        }
        if(*begin > min){
            return max(lengthOfLIS(begin + 1,end,min), 1 + lengthOfLIS(begin + 1,end,*begin));
        }else{
            return lengthOfLIS(begin + 1,end,min);
        }
    }
};
