//
//  Stack.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include "Stack.hpp"
#include <cstdlib>

Status InitStack(SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *)malloc((S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) {
            exit(OVERFLOW);
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.base == S.top) {
        return true;
    } else {
        return false;
    }
}
