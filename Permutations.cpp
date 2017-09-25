//
//  Permutations.cpp
//  leetcode
//
//  Created by witwolf on 5/13/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        permute(nums,0, (int) nums.size(),result);
        return result;
    }
    
    
private:
    void permute(vector<int>& nums,int i,int n,vector<vector<int> >& result){
        if(i == n-1){
            result.push_back(vector<int>(nums));
        }
        for(int j = i;j < n;++j){
            swap(nums[i], nums[j]);
            permute(nums,i+1,n,result);
            swap(nums[i], nums[j]);
        }
    }
};


int main(int argc,char **argv){
    
    Solution s;
    int nums[] = {1,2,2,2};
    vector<int> a = vector<int>(nums,nums+sizeof(nums)/sizeof(int));
    vector<vector<int> > result = s.permute(a);
    for(auto it = result.begin() ; it != result.end(); ++it){
        copy(it->begin(), it->end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
}
