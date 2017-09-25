//
//  RepeatedDNASequences.cpp
//  leetcode
//
//  Created by witwolf on 3/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    int four(char c){
        static int chars['T' - 'A'  + 1] = {
            0x0,0,0b1,0,0,
            0,0b10,0,0,0,
            0,0,0,0,0,
            0,0,0,0,0b11
        };
        return chars[c - 'A'];
    }
    
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
       
        int counter[1048576] = {0};
        
        int start = 0,end = 0;
        int num = 0 ;
        for(;end < s.length();end++){
            num <<= 2;
            num &= 0xfffff;
            num |= four(s[end]);
            if(end - start == 9){
                if(counter[num] == 1){
                    result.push_back(s.substr(start,10));
                }
                counter[num] += 1;
                start ++ ;
            }
        }
        return result;
    }
};


int main(int argc,char **argv){
    Solution s;
    string s1("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> result = s.findRepeatedDnaSequences(s1);
    copy(result.begin(),result.end(),ostream_iterator<string>(cout, " "));
    
    string s2("AAAAAAAAAAAAA");
    result = s.findRepeatedDnaSequences(s2);
    copy(result.begin(),result.end(),ostream_iterator<string>(cout, " "));
    
}
