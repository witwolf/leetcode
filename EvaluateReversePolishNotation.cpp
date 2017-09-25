//
//  EvaluateReversePolishNotation.cpp
//  leetcode
//
//  Created by witwolf on 5/4/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <vector>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for(auto token : tokens){
            if(token == "+"){
                calculate(operands, '+');
            }else if(token == "-"){
                calculate(operands, '-');
            }else if(token == "*"){
                calculate(operands, '*');
            }else if(token == "/"){
                calculate(operands, '/');
            }else{
                operands.push(atoi(token.c_str()));
            }
        }
        return operands.top();
    }
    
private:
    inline void calculate(stack<int> &operands,char op ){
        int rightOperand = operands.top();
        operands.pop();
        int leftOperand = operands.top();
        operands.pop();
        int result;
        switch (op) {
            case '+':
                result = leftOperand + rightOperand;
                break;
            case '-':
                result = leftOperand - rightOperand;
                break;
            case '*':
                result = leftOperand * rightOperand ;
                break;
            case '/':
                result = leftOperand / rightOperand;
                break;
            default:
                break;
        }
        operands.push(result);
    }
};
