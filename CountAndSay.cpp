//
//  CountAndSay.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <time.h>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string result;
        vector<pair<int,int> > v;
        v.push_back(make_pair(1, 1));
        vector<pair<int,int> > vtemp;
        while (--n > 1) {
            vtemp.clear();
            for(int i = 0; i < v.size(); ++i){
                push(vtemp,v[i]);
            }
            v = vtemp;
        }
        for(int i = v.size() -1 ; i >=0; --i){
            const pair<int,int> &p = v[i];
            result.push_back(p.first + '0');
            result.push_back(p.second + '0');
        }
        return result;
    }
    
    void push(vector<pair<int,int> > &v,pair<int,int> &p){
        // second
        if(!v.empty() && v.back().second == p.second){
            v.back().first += 1;
        }else{
            v.push_back(make_pair(1, p.second));
        }
        // first
        if(v.back().second == p.first){
            v.back().first += 1;
        }else{
            v.push_back(make_pair(1, p.first));
        }
    }
};

int main(int argc,char **argv){
    Solution s;
    time_t start = time(NULL);
    time_t end;
    for(int i = 20 ;i <= 100 ; ++i){
        s.countAndSay(i);
        end = time(NULL);
        cout << "cost " << end - start << " seconds to count " << i << endl;
        start = end;
    }
    
    
    
    
}