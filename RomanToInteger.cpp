//
//  RomanToInteger.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

int romanToInt(char* s) {
    int ret = 0;
    while(*s != '\0'){
        ret = ret * 10 + (*s - '0');
        s ++ ;
    }
    
    return ret;
}
