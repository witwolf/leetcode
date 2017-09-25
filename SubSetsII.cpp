//
//  SubSetsII.cpp
//  leetcode
//
//  Created by witwolf on 11/23/14.
//  Copyright (c) 2014 witwolf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(),S.end());
    vector<vector<int> > ret(1);
    size_t prev_size = 0;
    for(size_t i=0;i<S.size();++i){
        size_t ret_size = ret.size();
        for(size_t j=0;j<ret_size;++j){
            if(i==0 || S[i]!=S[i-1] || j>=prev_size){
                ret.push_back(ret[j]);
                ret.back().push_back(S[i]);
            }
        }
        prev_size = ret_size;
        
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
    int set1[] = {1,2,3};
    vector<int> s1(set1,set1+sizeof(set1)/sizeof(int));
    printHelper(subsetsWithDup(s1));
    
    int set2[] = {};
    vector<int> s2(set2,set2+sizeof(set2)/sizeof(int));
    printHelper(subsetsWithDup(s2));
    
    int set3[] = {1,2,2};
    vector<int> s3(set3,set3+sizeof(set3)/sizeof(int));
    printHelper(subsetsWithDup(s3));
    

}
