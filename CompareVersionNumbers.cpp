//
//  CompareVersionNumbers.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>

using namespace std;


int compareVersion(char* version1, char* version2) {
    int i = 0 ;
    int r = 0;
    while (true) {
        if(version1[i] == '\0' && version2[i] == '\0'){
            return r;
        }else if(version1[i] == '\0' && version2[i] != '\0'){
            return -1;
        }else if(version1[i] != '\0' && version2[i] == '\0'){
            return 1;
        }else if(version1[i] == '.' && version2[i] == '.'){
            if(r != 0){
                return r;
            }
        }else if (version1[i] == '.'){
            return -1;
        }else if(version2[i] == '.'){
            return 1;
        }else{
            if(r == 0){
                if(version1[i] > version2[i]){
                    r = 1;
                }else if(version1[i] < version2[i]){
                    r = -1;
                }
            }
        }
        ++ i;
    }
    return r;

}

int main(int argc,char **argv){
    cout << compareVersion("0.1", "1.1") << endl;
    cout << compareVersion("1.1", "1.2") << endl;
    cout << compareVersion("1.2", "13.37") << endl;
    cout << compareVersion("23.3", "23.4") << endl;
}


