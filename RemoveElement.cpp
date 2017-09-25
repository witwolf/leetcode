//
//  RemoveElement.cpp
//  leetcode
//
//  Created by witwolf on 5/11/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>


int removeElement(int* nums, int n, int val) {
    int count = 0;
    for(int i = 0 ; i < n ; ++i){
        if(nums[i] != val){
            nums[count++] = nums[i];
        }
    }
    return count;
}
