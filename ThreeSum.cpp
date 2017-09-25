//
//  ThreeSum.cpp
//  leetcode
//
//  Created by witwolf on 11/3/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(),num.end(),less<int>());
    
    vector<vector<int> > ret ;
    if(num.size() < 3){
        return ret;
    }
    for(int i = 0 ; i < num.size(); ++ i){
        int j = 0 , k = (int)num.size() - 1;
        while(j<i && k > i){
            if(num[i] + num[j] + num[k] < 0){
                ++ j ;
            }else if(num[i] + num[j] + num[k] > 0){
                -- k;
            }else{
                vector<int> value;
                value.push_back(num[j]);
                value.push_back(num[i]);
                value.push_back(num[k]);
                ret.push_back(value);
                ++ j;
                -- k;
            }
        }
    }
    
    return ret;
    
}

void printHelper(vector<vector<int> > threes){
    auto it = threes.begin();
    for( ; it != threes.end() ; ++ it){
        cout << '(' << (*it)[0] << ',' << (*it)[1] << ',' << (*it)[2] << ')' << endl;
    }
    cout << endl;
}


int main(int argc,char **argv){
    int test1[] = {2,1};
    vector<int> num1(test1,test1+sizeof(test1)/sizeof(int));
    (threeSum(num1));
    
    
    int test2[] = {3,7,0,-10,2,8};
    vector<int> num2(test2,test2+sizeof(test2)/sizeof(int));
    printHelper(threeSum(num2));
    
    
    int test3[] = {-1,1,0,2,3,-2,7};
    vector<int> num3(test3,test3+sizeof(test3)/sizeof(int));
    printHelper(threeSum(num3));
    
    int test4[] = {0,8,17,3,-91,83,18,7,6,4,-8,-91,53,67};
    vector<int> num4(test4,test4+sizeof(test4)/sizeof(int));
    printHelper(threeSum(num4));
    
}