//
//  AddBinary.cpp
//  leetcode
//
//  Created by witwolf on 5/8/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        auto length = max(a.length(),b.length());
        a.append(length-a.length(),'0');
        b.append(length-b.length(),'0');
        char base = 0;
        for(auto k = 0 ; k < length ; ++k){
            base += a[k] + b[k] - 2 * '0';
            a[k] = base % 2 + '0';
            base = base / 2;
        }
        if(base){
            a.push_back('1');
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

int main(int argc,char **argv){
    string a,b;
    Solution s;
    while(true){
        cin >> a >> b;
        cout << s.addBinary(a, b) << endl;
    }
}
