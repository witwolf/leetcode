//
//  CanJump.cpp
//  leetcode
//
//  Created by witwolf on 11/4/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <iostream>
using namespace std;

bool canJump(int A[],bool jumpFlag[],int curPos,int endPos);

bool canJump(int A[], int n) {
    
    bool *jumpFlag = new bool[n];
    memset(jumpFlag, 0, n);
    return canJump(A, jumpFlag,0,n-1);
    
}

bool canJump(int A[] ,bool jumpFlag[],int curPos, int endPos){
    if(curPos == endPos){
        return true;
    }
    
    // backward
    int nextPos = curPos - A[curPos];
    if(nextPos >= 0 && !jumpFlag[nextPos]){
        jumpFlag[nextPos] = true;
        if(canJump(A,jumpFlag,nextPos,endPos)){
            return true;
        }
        jumpFlag[nextPos] = false;
    }
    
    // forward
    nextPos = curPos + A[curPos];
    if(nextPos <= endPos && !jumpFlag[nextPos]){
        jumpFlag[nextPos] = true;
        if(canJump(A, jumpFlag,nextPos,endPos)){
            return true;
        }
        jumpFlag[nextPos] = false;
    }
    return false;
}

int main(int argc,char **argv){
    int A1[] = {2,3,1,1,4};
    cout << canJump(A1, sizeof(A1)/sizeof(int)) << endl;
    
    int A2[] = {3,2,1,0,4};
    cout << canJump(A2,sizeof(A2)/sizeof(int)) << endl;
    
    
}
