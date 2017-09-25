//
//  RectangleArea.cpp
//  leetcode
//
//  Created by witwolf on 6/8/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//


#include <iostream>
using namespace std;

class Solution {
public:
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area  = (D - B ) * (C - A ) + (G - E) * (H - F);
        if(E >= C || A >= G || B >= H || F >= D){
            return area;
        }
        // A C E G
        int width = min(C,G) - max(A,E);
        // B D F H
        int height = min(D,H) - max(B,F);
        return  area -  width * height;
    }
};
