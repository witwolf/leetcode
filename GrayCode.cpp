//
//  GrayCode.cpp
//  leetcode
//
//  Created by witwolf on 11/25/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i=0;i<n;++i){
            size_t j = result.size();
            while(j--){
                int value = result[j];
                value ^= 1<<i;
                result.push_back(value);
            }
        }
        return result;
    }
};

int main(int argc,char **argv){
    Solution s;
    vector<int> result = s.grayCode(1);
    copy(result.begin(),result.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    
    result = s.grayCode(2);
    copy(result.begin(),result.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    
    result = s.grayCode(3);
    copy(result.begin(),result.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
}
