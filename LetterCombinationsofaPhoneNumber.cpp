//
//  LetterCombinationsofaPhoneNumber.cpp
//  leetcode
//
//  Created by witwolf on 4/29/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return vector<string>();
        }
        vector<string> result(1,"");
        string keyboard[]= {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        for(auto digit:digits){
            auto chars = keyboard[digit - '0'];
            size_t result_size = result.size();
            size_t chars_size = chars.size();
            if(chars_size == 0){
                continue;
            }
            result.resize( result_size * chars_size);
            // copy chars_size 份
            for(auto i = 0 ; i < chars_size ; ++i){
                copy(result.begin(),result.begin() + result_size,result.begin() + result_size * i);
            }
            for(auto i = 0 ; i < chars_size; ++i){
                for(auto j = i * result_size ; j < i * result_size + result_size ; ++ j){
                    result[j].push_back(chars[i]);
                }
            }
        }
        return result;
    }
};


int main(int argc,char **argv){
    Solution solution;
    string s;
    while (true) {
        cin >> s;
        cout << s << ":" ;
        vector<string> result = solution.letterCombinations(s);
        copy(result.begin(),result.end(),ostream_iterator<string>(cout," "));
        cout << endl;
    }
}

