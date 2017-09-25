//
//  ReverseInteger.cpp
//  leetcode
//
//  Created by witwolf on 5/11/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>


int reverse(int x) {
    int value = 0 ;
    while(x){
        value = value * 10 + x % 10;
        x = x / 10;
    }
    return value;
}

int main(int argc,char **argv){
    printf("%d\n",reverse(0));
    printf("%d\n",reverse(1534236469));
    printf("%d\n",reverse(120300));

}