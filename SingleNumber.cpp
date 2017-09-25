//
//  SingleNumber.cpp
//  leetcode
//
//  Created by witwolf on 11/29/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        return accumulate(A, A+n,0, bit_xor<int>());
    }
};


int main(int argc,char **argv){
    Solution s;
    
    int a1[] = {1};
    cout << s.singleNumber(a1, sizeof(a1)/sizeof(int)) << endl;
    
    int a2[] = {1,2,3,4,5,5,4,3,2};
    cout << s.singleNumber(a2, sizeof(a2)/sizeof(int)) << endl;
}