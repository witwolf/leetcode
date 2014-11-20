//
//  DivideTwoIntegers.cpp
//  leetcode
//
//  Created by witwolf on 11/19/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    
    dividend = dividend < 0 ? -dividend : dividend;
    divisor = divisor < 0 ? -divisor : divisor;
    
    int quotient  = 0;
    while(dividend >= divisor){
        int c = divisor;
        for(int i = 0 ; dividend>=c ; ++i,c <<= 1 ){
            dividend -= c;
            quotient += 1 << i ;
        }
    }
    return dividend ^ divisor >> 31 ? -quotient  : quotient  ;
}

int main(int argc,char **argv){
    
    std::cout << divide(18, 5) << std::endl;
    std::cout << divide(5,18) << std::endl;
    std::cout << divide(-18, -5) << std::endl;
    std::cout << divide(-5,18) << std::endl;
    std::cout << divide(-18, 5) << std::endl;
    std::cout << divide(5,-18) << std::endl;
    std::cout << divide(18, -5) << std::endl;
    std::cout << divide(-5, -18) << std::endl;
    
}
