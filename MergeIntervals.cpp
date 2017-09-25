//
//  MergeIntervals.cpp
//  leetcode
//
//  Created by witwolf on 5/11/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()){
            return result;
        }
        sort(intervals.begin(), intervals.end(),[](const Interval& lhs,const Interval &rhs){
            return (lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end));
        });
        result.push_back(*intervals.begin());
        for(auto &interval:intervals){
            Interval &back = result.back();
            if(back.end < interval.start){
                result.push_back(interval);
            }else if(back.end >= interval.start && back.end <= interval.end){
                back.end = interval.end;
            }

        }
        return result;
    }
};
