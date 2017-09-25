//
//  GasStation.cpp
//  leetcode
//
//  Created by witwolf on 3/31/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = (int) gas.size();
        int *data = new int[size];
        memset(data, 0, size);
        for(int i=0;i<size;i++){
            data[i] = gas[i] - cost[i];
        }
        int i = 0 , j = 0;
        int gasLeft = 0;
        while (i<size && j < i+size) {
            if (i == j){
                gasLeft = data[i];
                j =  i;
            }
            if(gasLeft < 0){
                gasLeft -= data[i++];
            }else if(gasLeft >=0 && j - i == size -1){
                return i;
            }else{
                j++;
                gasLeft += data[ j % size];
            }
        }
        return -1;
    }
};

int main(int argc,char **argv){
    Solution s;
    int gas1[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
    int cost1[] = {27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    vector<int> g1(gas1,gas1+sizeof(gas1)/sizeof(int));
    vector<int> c1(cost1,cost1+sizeof(cost1)/sizeof(int));
    cout << s.canCompleteCircuit(g1, c1) << endl;
    
}