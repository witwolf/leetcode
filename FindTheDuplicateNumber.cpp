//
//  FindTheDuplicateNumber.cpp
//  leetcode
//
//  Created by YingXiang Hong on 10/9/15.
//  Copyright © 2015 witwolf. All rights reserved.
//

#include <stdio.h>

int findDuplicate(int *nums,int start,int end){
    if(start == end){
        return nums[start];
    }
    int mid = (start + end) / 2;
    int count = 0;
    int i = 0;
    while(i <= mid){
        if(nums[i] <= mid){
            count ++ ;
        }
        i++;
    }
    return count < mid ? findDuplicate(nums,mid,end) : findDuplicate(nums,start,mid);
}

int findDuplicate(int* nums, int numsSize) {
    return findDuplicate(nums,0,numsSize-1);
}
