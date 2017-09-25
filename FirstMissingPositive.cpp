//
//  FirstMissingPositive.cpp
//  leetcode
//
//  Created by witwolf on 4/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b ;
    *b = temp;
}

void bucketSort(int *nums,int numsSize){
    for(int i=0;i<numsSize;++i){
        while(nums[i] != i+1){
            if(nums[i] <= 0 || nums[i] > numsSize || nums[i] == nums[nums[i] - 1] ){
                break;
            }
            swap(&(nums[i]),&(nums[nums[i] - 1]));
        }
    }
}

int firstMissingPositive(int* nums, int numsSize) {
    bucketSort(nums, numsSize);

    for(int i=0;i<numsSize;++i){
        if(nums[i] != (i + 1)){
            return i+ 1;
        }
    }
    return numsSize + 1;
}



