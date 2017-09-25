//
//  3SumClosest.cpp
//  leetcode
//
//  Created by witwolf on 5/2/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        size_t i,j,k;
        int sumClosest = nums[0] + nums[1] + nums[2];
        for(i=1; i<nums.size()-1; ++i){
            j = 0;
            k = nums.size() - 1;
            while(j<i && k >i){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return sum;
                }else if(sum > target){
                    --k ;
                }else{
                    ++j;
                }
                if(abs(sum-target) < abs(sumClosest-target)){
                    sumClosest = sum;
                }
            }
        }
        
        return sumClosest;
    }
};

int main(int argc,char **argv){
    Solution s;
    srand(time(0));
    int n = 100 ;
    while(n--){
        int numSize = rand() % 20 ;
        if (numSize > 0){
            int target = rand() % 1000;
            vector<int> nums ;
            nums.resize(numSize);
            for(int i = 0;i<numSize;++i){
                nums[i] = rand() % 1000;
            }
            
            
            cout << "Nums: " ;
            copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
            cout << ", Target :" << target  << ",answer:" << s.threeSumClosest(nums,target) << endl;
            
        }
        
    }
}
