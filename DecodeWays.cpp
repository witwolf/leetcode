//
//  DecodeWays.cpp
//  leetcode
//
//  Created by witwolf on 4/24/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
using namespace std;

int numDecodings(char* s) {
    if(s == NULL || *s == '\0' || *s == '0')
        return 0;
    // one 最后一个字母是由1-9组成的
    // two 最后一个字母是由10-26组成的
    // all 为 one与two的和
    int one = 1,two=0,all=1;
    s ++ ;
    while(*s){
        
        if(*s == '0'){
            if(*(s-1) !='1' && *(s-1) != '2'){
                return 0;
            }
            // 当前数字为'0',最后一个字母必定由两个数字组成
            all = two = one ;
            one = 0;
        }else if(*(s-1) == '0'){
            // 前面一个数字为 '0',最后一个字母必定由一个数字组成
            all = one = two;
            two = 0;
        }else{
            // 如果是10-26
            if( *(s-1) =='1' ||(*(s-1) == '2' && *s <= '6')){
                int temp = one;
                one = one + two;
                two = temp;
                all = two + one;
            }else{
                all = one = one + two;
                two = 0;
            }
        }
        s++;
    }
    return all;
}


int main(int argc,char **argv){
    cout << numDecodings(NULL) << endl;
    cout << numDecodings("") << endl;
    cout << numDecodings("1234561221") << endl;
    cout << numDecodings("11") << endl;
    cout << numDecodings("1231") << endl;
    cout << numDecodings("10") << endl;
    cout << numDecodings("1090") << endl;
    cout << numDecodings("10900") << endl;
    cout << numDecodings("230") << endl;
    cout << numDecodings("10") << endl;
    cout << numDecodings("17") << endl;
}


