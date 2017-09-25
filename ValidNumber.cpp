//
//  ValidNumber.cpp
//  leetcode
//
//  Created by witwolf on 8/22/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>

bool isNumber(char* s) {
    // 去除前面的空白字符
    while(*s == ' '){
        s ++ ;
    }
    int dot_count = 0;
    int e_count = 0;
    int s_count = 0;
    int n_count = 0;
    int i = 0;
    while(*s){
        if(s_count && *s != ' '){
            return false;
        }else if(*s == '.'){
            // 逗号只能出现一次，且在e出现之前，逗号前或后必须是数字
            if(dot_count || e_count){
                return false;
            }
            dot_count ++ ;
        }else if(*s == '-'){
            // 负号只能出现在首位或e后面，且不能出现在未尾
            if( *(s+1) == '\0' || (i != 0 && *(s-1) != 'e')){
                return false;
            }
        }else if(*s == 'e'){
            // e只能出现一次，且不能出现在首尾
            if(e_count || i == 0 || *(s+1) == '\0'){
                return false;
            }
            e_count ++;
        }else if(*s == ' '){
            s_count ++ ;
        }
        else if(*s >= '0' && *s <= '9'){
            n_count ++ ;
        }else{
            return false;
        }
        i ++;
        s ++;
    }
    return n_count && i;
}


