//
//  NumberOfOneBits.cpp
//  leetcode
//
//  Created by witwolf on 4/1/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
using namespace std;

int hammingWeight(uint32_t  n) {
    int bits = 0;
    while(n){
        ++ bits ;
        n &= n-1;
    }
    return bits;
}

int main(int argc,char **argv){
    std::cout << hammingWeight(-1) << endl;
    std::cout << hammingWeight(15) << endl;
    std::cout << hammingWeight(1) << endl;
    std::cout << hammingWeight(16) << endl;
    std::cout << hammingWeight(19) << endl;
    std::cout << hammingWeight(0) << endl;
}

