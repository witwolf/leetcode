//
//  JumpGameII.cpp
//  leetcode
//
//  Created by witwolf on 11/18/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int jump(int A[], int n) {
    
    int i = 0;
    int maxPos=0,steps=0;
    for(;i<n;++i){
        if(A[i]+i > maxPos){
            maxPos = A[i]+i;
            ++ steps;
        }
        if(maxPos >= n-1){
            return steps;
        }
    }
    return steps;
}

int main(int argc,char **argv){
    int test1[] = {2,3,1,1,4};
    std::cout << jump(test1,sizeof(test1)/sizeof(int)) << std::endl;
    
    int test2[] = {1,5,1,1,8,1,1,1,1,1};
    std::cout << jump(test2, sizeof(test2)/sizeof(int)) << std::endl;
}