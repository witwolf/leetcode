//
//  LengthOfLastWord.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>

using namespace std;


int lengthOfLastWord(char* s) {
    int start = -1 ,length = 0;
    int i = 0;
    while (*s != '\0') {
        if(*s == ' '){
            start = i ;
        }else{
            length = i - start ;
        }
        ++ s;
        ++ i;
    }
    return length;
}

int main(int argc,char **argv){
    cout << lengthOfLastWord("   ") << endl;
    cout << lengthOfLastWord("h") << endl;
    cout << lengthOfLastWord("he") << endl;
    cout << lengthOfLastWord(" he") << endl;
    cout << lengthOfLastWord("he ") << endl;
    cout << lengthOfLastWord(" he ") << endl;
    cout << lengthOfLastWord("  h de ") << endl;
    cout << lengthOfLastWord("hello world") << endl;

}
