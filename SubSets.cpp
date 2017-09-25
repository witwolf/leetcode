//
//  SubSets.cpp
//  leetcode
//
//  Created by witwolf on 11/21/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ret ;
    ret.push_back(vector<int>());
    for(auto it=S.begin();it!=S.end();++it){
        long size = ret.size();
        for(int i=0;i<size;++i){
            vector<int> subset(ret[i]);
            subset.push_back(*it);
            ret.push_back(subset);
        }
    }
    return ret;
}

void printHelper(vector<vector<int> >Ss){
    std::cout << '[' << std::endl;
    for(auto outer = Ss.begin();outer!=Ss.end();++outer){
        if(outer!=Ss.begin()){
            cout << " ,\n";
        }
        cout << "\t[" ;
        for(auto inner=outer->begin();inner!=outer->end();++inner){
            if(inner != outer->begin()){
                cout << ", ";
            }
            cout << *inner;
        }
        cout << ']';
    }
    cout << "\n]\n" << endl;
}


int main(int argc,char **argv){
    int set1[] = {1,2,3,4};
    vector<int> s1(set1,set1+sizeof(set1)/sizeof(int));
    printHelper(subsets(s1));
    
    int set2[] = {};
    vector<int> s2(set2,set2+sizeof(set2)/sizeof(int));
    printHelper(subsets(s2));
    
}
