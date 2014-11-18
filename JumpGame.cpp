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
    
    
    int coverPos = 0 ;
    for(int i = 0 ; i <= coverPos && i < n ; i++ ){
        if(coverPos < A[i] + i){
            coverPos = A[i] + i;
        }
        
        if(coverPos >= n-1){
            return true;
        }
    }
    
    return false;
    
}


int main(int argc,char **argv){
    int A1[] = {2,3,1,1,4};
    cout << canJump(A1, sizeof(A1)/sizeof(int)) << endl;
    
    int A2[] = {3,2,1,0,4};
    cout << canJump(A2,sizeof(A2)/sizeof(int)) << endl;
    
    
}
