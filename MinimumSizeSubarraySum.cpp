//
//  MinimumSizeSubarraySum.cpp
//  leetcode
//
//  Created by witwolf on 5/19/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int minLength = INT_MAX;
        int i = 0 , j = 0;
        while (j < nums.size()) {
            sum += nums[j++];
            if(sum < s){
                continue;
            }
            while (sum - nums[i] >= s) {
                sum -= nums[i++];
            }
            if (minLength > j-i){
                minLength = j-i;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};



int main(int arg,char **argv){
    int arr[] = {2,3,1,2,4,3};
    vector<int> v(arr,arr+6);
    Solution s;
    cout << s.minSubArrayLen(7, v) << endl;
}