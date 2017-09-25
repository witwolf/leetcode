//
//  ExcelSheetColumnTitle.cpp
//  leetcode
//
//  Created by witwolf on 4/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n){
            n -= 1;
            s.push_back(n % 26 + 'A');
            n = n / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


int main(int argc,char **argv){
    Solution s;
    for(int i = 1 ; i <= 28 * 26 ; ++i){
        cout << i << ":" << s.convertToTitle(i) << endl;
    }
    
}