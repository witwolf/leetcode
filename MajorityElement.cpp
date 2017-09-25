//
//  MajorityElement.cpp
//  leetcode
//
//  Created by witwolf on 4/24/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int num = *nums,count = 1;
    int i = 1;
    for(;i<numsSize;++i){
        if(*(nums + i) == num){
            ++ count;
        }else{
            -- count;
            if(count == 0){
                count = 1;
                num = *(nums +(++i));
            }
        }
    }
    return num;
}
