//
//  TwoSum.cpp
//  leetcode
//
//  Created by witwolf on 10/24/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0 , j = (int) numbers.size() - 1;
        
        while(i < j ){
            if(numbers[i] + numbers[j] < target){
                i++ ;
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                break;
            }
        }
        
        vector<int> ret;
        ret.push_back(i);
        ret.push_back(j);
        
        return ret;
        
    }
    
};


int main(int argc,char **argv){
    int data[] = {2,7,11,15};
    vector<int> numbers(data,data + sizeof(data)/sizeof(int));
    int target = 9 ;
    
    Solution s;
    vector<int> ret = s.twoSum(numbers, target);
    
    std::cout << "index1=" << ret[0] << ", index2=" << ret[1] << std::endl; ;


    
}