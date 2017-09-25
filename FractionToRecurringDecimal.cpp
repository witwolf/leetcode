//
//  FractionToRecurringDecimal.cpp
//  leetcode
//
//  Created by witwolf on 5/12/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = integerPart(numerator, denominator);
        if(numerator != 0){
            result.append(".").append(fractionalPart(numerator, denominator));
        }
        return result;
    }
    
    
private:
    inline string fractionalPart(int numerator,int denominator){
        string result;
        map<int,size_t> pos;
        while(numerator){
            numerator  *= 10;
            if(pos.find(numerator) != pos.end()){
                result.insert(pos[numerator], 1,'(');
                result.push_back(')');
                break;
            }
            pos[numerator] = result.size();
            result.push_back(numerator / denominator + '0');
            numerator %= denominator;
        }
        return result;
    }
    
    inline string integerPart(int &numerator,int &denominator){
        int integer_part = numerator / denominator;
        numerator = abs( numerator % denominator );
        denominator = abs(denominator);
        return itoa(integer_part);
    }
    
    inline string itoa(int i){
        stringstream ss;
        ss << i;
        return ss.str();
    }
};


int main(int argc,char **argv){
    Solution s;
    while(true){
        int numerator,demoninator;
        cin >> numerator >> demoninator ;
        cout << numerator << '/' << demoninator << '=' << s.fractionToDecimal(numerator, demoninator) << endl;
    }
}
