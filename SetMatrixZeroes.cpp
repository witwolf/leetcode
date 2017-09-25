//
//  SetMatrixZeroes.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>

#include <cstdlib>
#include <ctime>
#include <utility>
#include <ctime>
#include <iostream>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    time_t setZeroes(vector<vector<char> > &matrix) {
        time_t start = time(0);
        const size_t rows = matrix.size();
        const size_t columns = matrix[0].size();
        
        vector<bool> rowFlag(rows,false);
        vector<bool> columnFlag(columns,false);
        
        for(int i = 0 ; i < rows; ++i){
            for(int j = 0 ; j < columns ; ++j){
                if(matrix[i][j] == 0){
                    rowFlag[i] = true;
                    columnFlag[j] = true;
                }
            }
        }
        
        for(int i = 0 ; i < rows; ++i){
            if(rowFlag[i] ){
                for(int j = 0 ; j < columns ; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 0 ; j < columns ; ++j){
            if(columnFlag[j] ){
                for(int i = 0 ; i < rows ; ++ i){
                    matrix[i][j] = 0;
                }
            }
        }
        return time(0) - start;
    }
};



