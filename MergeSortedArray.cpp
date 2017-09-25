//
//  MergeSortedArray.cpp
//  leetcode
//
//  Created by witwolf on 5/10/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
using namespace std;



void merge(int* nums1, int m, int* nums2, int n) {
    int lagest;
    for(int i = m + n - 1 ; i >= 0 ; --i){
        if(n < 1){
            break;
        }
        if(m > 0 && nums1[m-1] > nums2[n-1]){
            lagest = nums1[m-1];
            -- m;
        }else{
            lagest = nums2[n-1];
            -- n;
        }
        nums1[i] = lagest;
    }
}

