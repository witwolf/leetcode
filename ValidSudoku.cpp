//
//  ValidSudoku.cpp
//  leetcode
//
//  Created by witwolf on 4/24/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

bool vaildFlag(char c,char flags[]){
    if(c != '.'){
        if(flags[c-'1'] ++){
            return false;
        }
    }
    return true;
}

bool isValidSudoku(char board[9][9]) {
    char flags[9];
    int column,row;
    for(column=0;column < 9;++column){
        memset(flags, 0, 9);
        for(row=0;row<9;++row){
            if(!vaildFlag(board[row][column],flags))
               return false;
        }
        memset(flags, 0, 9);
        for(row=0;row<9;++row){
            if(!vaildFlag( board[column][row],flags))
               return false;
        }
    }
    int i = 0;
    char rowBases[] = {
        0,0,0,
        3,3,3,
        6,6,6
    };
    char columnBases[] = {
        0,3,6,
        0,3,6,
        0,3,6
    };
    for(i=0;i<9;++i){
        memset(flags, 0, 9);
        int rowBase = rowBases[i],columnBase = columnBases[i];
        for(row=0;row<3;++row){
            for(column=0;column<3;++column){
                if(!vaildFlag( board[rowBase+ row][columnBase+ column],flags))
                    return false;
            }
        }
    }
    return true;
}