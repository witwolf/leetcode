//
//  RangeSumQuery.cpp
//  leetcode
//
//  Created by YingXiang Hong on 11/11/15.
//  Copyright © 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


struct NumArray {
    int *nums;
    int *sum;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    
    struct NumArray * arr = (struct NumArray *) malloc(sizeof(struct NumArray));
    int *sum = (int *) malloc(sizeof(int) * numsSize);
    sum[0] = nums[0] ;
    int i = 0;
    for(i=1;i<numsSize ;i++){
        sum[i] = nums[i] + sum[i-1];
    }
    arr->nums = nums;
    arr->sum = sum;
    return arr;
    
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return numArray->sum[j] - numArray->sum[i] + numArray->nums[i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sum);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);