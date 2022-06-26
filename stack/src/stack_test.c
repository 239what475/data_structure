//
// Created by zhuzh on 2022/6/23.
//

#include "stack_test.h"
#include "sq_stack.h"

Status Conditional_Add(ElemType *e) {
    if (*e > 10) return ERROR;
    *e += 20;
    return OK;
}

__attribute__((unused)) void Test_Sq_Stack() {
    SqStack S;
    InitStack_Sq(&S);
    Push_Sq(&S, 10);
    Display_Sq(&S);

    ElemType e;
    GetTop_Sq(&S, &e);
    printf("top of stack : %d \n", e);

    Push_Sq(&S, 20);
    Display_Sq(&S);
    Pop_Sq(&S, &e);
    printf("pop top of stack %d \n", e);
    Display_Sq(&S);

    printf("add 20 to number smaller 10 \n");
    StackTraverse_Sq(&S,Conditional_Add);
    Display_Sq(&S);

    DestroyStack_Sq(&S);

//  算法 3.1
//    conversion();

//  算法 3.2
//    line_edit();
}
