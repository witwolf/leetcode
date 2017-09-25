//
//  SingleNumberII.cpp
//  leetcode
//
//  Created by witwolf on 11/28/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0,twos = 0;
        for(int i=0;i<n;++i){
            ones = (ones ^ A[i]) & ~twos;
            twos = (twos ^ A[i]) & ~ones;
        }
        return ones;
    }
};


int main(int argc,char **argv){
    Solution s;
    
    int a1[] = {1,2,3,3,2,2,3,1};
    cout << s.singleNumber(a1, sizeof(a1)/sizeof(int)) << endl;
    
    int a2[] = {1,1,1,2,3,2,2};
    cout << s.singleNumber(a2, sizeof(a2)/sizeof(int)) << endl;

}
