//
//  MaximumSubarray.cpp
//  leetcode
//
//  Created by witwolf on 5/5/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

int maxSubArray(int* nums, int numsSize) {
    int sum = 0 ;
    int maxSum = 0;
    for(int i=0;i<numsSize;++i){
        sum += nums[i];
        if(sum > maxSum){
            maxSum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    if(maxSum == 0){
        maxSum = nums[0];
        for(int i = 1 ; i < numsSize; ++i){
            if(maxSum < nums[i]){
                maxSum = nums[i];
            }
        }
    }
    return maxSum;
}
