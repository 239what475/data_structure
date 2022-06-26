//
// Created by zhuzh on 2022/6/23.
//

#ifndef DATA_STRUCTURE_SQ_STACK_H
#define DATA_STRUCTURE_SQ_STACK_H

#include "common.h"

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct {
    ElemType *base;
    ElemType *top;
    int stack_size;
} SqStack;

Status InitStack_Sq(SqStack *S);

Status DestroyStack_Sq(SqStack *S);

Status ClearStack_Sq(SqStack *S);

Status StackEmpty_Sq(SqStack *S);

int StackLength_Sq(SqStack *S);

Status GetTop_Sq(SqStack *S, ElemType *e);

Status Push_Sq(SqStack *S, ElemType e);

Status Pop_Sq(SqStack *S, ElemType *e);

Status Display_Sq(SqStack *S);

Status StackTraverse_Sq(SqStack *S, Status (*visit)(ElemType *e));

void conversion();

void line_edit();

#endif //DATA_STRUCTURE_SQ_STACK_H
