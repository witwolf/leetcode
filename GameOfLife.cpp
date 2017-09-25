//
//  GameOfLife.cpp
//  leetcode
//
//  Created by YingXiang Hong on 10/8/15.
//  Copyright © 2015 witwolf. All rights reserved.
//

// 1 2 3
// 4 u 5
// 6 7 8

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        long rows = board.size();
        long cols = board[0].size();
        for(long row = 0; row < rows ; row++){
            for(long col = 0 ; col < cols; ++col){
                countLiveNeighbors(board, rows, cols,row,col);
            }
        }
        for(long row = 0 ; row < rows; row++){
            for(long col=0;col<cols;++col){
                nextState(board, row, col);
            }
        }
    }

private:
    void countLiveNeighbors(vector<vector<int> > & board,long rows,long cols,long row,long col){
        int neighborsCount = 0 ;
        for(long i = row -1; i <= row + 1; i++){
            for(long j = col-1;j<=col+1;j++){
                if(i < 0 || j < 0 || i >= rows || j >= cols || (i == row && j == col)){
                    continue;
                }
                neighborsCount += (board[i][j] & 0x01);
                
            }
        }
        board[row][col] |= neighborsCount << 1;
    }
    
    void nextState(vector<vector<int> > &board , long row ,long col){
        int neighborsCount = board[row][col] >> 1;
        int state = board[row][col] & 0x01;
        if(state){
            if(neighborsCount < 2 || neighborsCount > 3){
                board[row][col] = 0;
            }
        }else{
            if(neighborsCount == 3){
                board[row][col] = 1;
            }
        }
        board[row][col] &= 0x01;
        
    }
};

int main(int argc,char **argv){
    vector<int> rows1;
    rows1.push_back(1);
    rows1.push_back(1);
    
    vector<int> rows2;
    rows2.push_back(1);
    rows2.push_back(0);
    
    
    
    vector<vector<int> > rows ;
    rows.push_back(rows1);
    rows.push_back(rows2);
    
    Solution s;
    s.gameOfLife(rows);
}