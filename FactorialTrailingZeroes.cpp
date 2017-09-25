//
//  FactorialTrailingZeroes.cpp
//  leetcode
//
//  Created by witwolf on 4/29/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int size = 0;
    while(n ){
        size += n / 5;
        n = n / 5;
    }
    return size;
}


int main(int argc,char **argv){

    for(int i = 1; i <= 100 ; ++ i){
        cout << i << "! contains " << trailingZeroes(i) << " zeros" << endl;
    }
    
}