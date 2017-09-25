//
//  MinStack.cpp
//  leetcode
//
//  Created by witwolf on 4/28/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        _s.push(x);
        if(!_minS.empty() && x > _minS.top()){
            _minS.push(_minS.top());
        }else{
            _minS.push(x);
        }
    }
    
    void pop() {
        _s.pop();
        _minS.pop();
    }
    
    int top() {
        return _s.top();
    }
    
    int getMin() {
        return _minS.top();
    }
    
private:
    stack<int> _s;
    stack<int> _minS;
};
