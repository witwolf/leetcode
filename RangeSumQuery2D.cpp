//
//  RangeSumQuery2D.cpp
//  leetcode
//
//  Created by YingXiang Hong on 11/12/15.
//  Copyright © 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


struct NumMatrix {
    int **matrix;
    int **rangeSum;
    int matrixRowSize;
    int matrixColSize;
    
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    struct NumMatrix * numMatrix = (struct NumMatrix *) malloc(sizeof(struct NumMatrix));
    int **rangeSum = (int **) malloc(sizeof(int*) * matrixRowSize);
    int r = 0,c=0;
    for(;r<matrixRowSize;r++){
        rangeSum[r] = (int *) malloc(sizeof(int) * matrixColSize);
    }
    rangeSum[0][0] = matrix[0][0];
    for(c=1;c<matrixColSize;c++){
        rangeSum[0][c] = rangeSum[0][c-1] + matrix[0][c];
    }
    for(r=1;r<matrixRowSize;r++){
        rangeSum[r][0] = rangeSum[r-1][0] + matrix[r][0];
    }
    for(r=1;r<matrixRowSize;r++){
        for(c=1;c<matrixColSize;c++){
            rangeSum[r][c] = rangeSum[r][c-1] + rangeSum[r-1][c] + matrix[r][c] - rangeSum[r-1][c-1] ;
        }
    }
    
    numMatrix->matrix = matrix;
    numMatrix->matrixRowSize = matrixRowSize;
    numMatrix->matrixColSize = matrixColSize;
    numMatrix->rangeSum = rangeSum;
    return numMatrix;
}

int sumRect(struct NumMatrix* numMatrix,int row,int col){
    if(row < 0 || col < 0){
        return 0;
    }
    return numMatrix->rangeSum[row][col];
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int sumRegion1 = sumRect(numMatrix,row1-1,col1-1); // (0,0,row1-1,col1-1)
    int sumRegion2 = sumRect(numMatrix,row1-1,col2); // (0,0,row1-1,col2)
    int sumRegion3 = sumRect(numMatrix,row2,col1-1); // (0,0,row2,col1-1)
    int sumRegion4 = sumRect(numMatrix,row2,col2); // (0,0,row2,col2)
    
    return sumRegion4 - sumRegion3 - sumRegion2 + sumRegion1;
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {
    int r = 0 ;
    for(;r<numMatrix->matrixRowSize;r++){
        free(numMatrix->rangeSum[r]);
    }
    free(numMatrix->rangeSum);
    free(numMatrix);
}


int main(int argc,char **argv){
    int r1[] = {3,0,1,4,2};
    int r2[] = {5,6,3,2,1};
    int r3[] = {1,2,0,1,5};
    int r4[] = {4,1,0,1,7};
    int r5[] = {1,0,3,0,5};
    
    int* matrix[] = {r1,r2,r3,r4,r5};
    struct NumMatrix* numMatrix = NumMatrixCreate(matrix, 5, 5);
    printf("%d\n",sumRegion(numMatrix, 1, 1, 2, 2));
    
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);
