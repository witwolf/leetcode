//
//  ValidAnagram.cpp
//  leetcode
//
//  Created by witwolf on 8/3/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>



bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    char *c = s;
    while(*c){
        count[*(c++) - 'a'] ++;
    }
    c = t;
    while(*c){
        count[*(c++) - 'a'] --;
    }
    int i = 0 ;
    for(i = 0 ; i < 26 ; ++i){
        if(count[i] != 0){
            return false;
        }
    }
    return true;
}
