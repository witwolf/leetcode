//
//  RotateArray.cpp
//  leetcode
//
//  Created by witwolf on 5/10/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        if(size != 0 && k % size != 0){
            k = k % size;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k , nums.end());
        }
    }
};


int main(int argc,char **argv){
    
}