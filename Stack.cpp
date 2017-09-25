//
//  Stack.cpp
//  leetcode
//
//  Created by witwolf on 7/30/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct _Node {
    int val;
    _Node * prev;
};
typedef _Node Node;

struct _Stack{
    Node * top;
};

typedef _Stack Stack;

Stack* init_stack(){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void pop_stack(Stack * stack){
    Node * top = stack->top;
    stack->top = top->prev;
    free(top);
}

void push_stack(Stack *stack,int val){
    Node *top = (Node*) malloc(sizeof(Node));
    top->val = val;
    top->prev = stack->top;
    stack->top = top;
}

int top_stack(Stack * stack){
    return stack->top->val;
}

