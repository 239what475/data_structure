//
// Created by zhuzh on 2022/6/26.
//

#ifndef DATA_STRUCTURE_C_QUEUE_H
#define DATA_STRUCTURE_C_QUEUE_H

#include "common.h"

#define MAXQSIZE 100

typedef struct {
    ElemType *base;
    int front;
    int rear;
} CircleQueue;

Status InitQueue_C(CircleQueue *Q);

Status DestroyQueue_C(CircleQueue *Q);

Status ClearQueue_C(CircleQueue *Q);

bool QueueEmpty_C(CircleQueue *Q);

int QueueLength_C(CircleQueue *Q);

Status QueueDisplay_C(CircleQueue *Q);

Status GetHead_C(CircleQueue *Q,ElemType *e);

Status EnQueue_C(CircleQueue *Q,ElemType e);

Status DeQueue_C(CircleQueue *Q,ElemType *e);

Status QueueTraverse_C(CircleQueue *Q,void visit());

#endif //DATA_STRUCTURE_C_QUEUE_H
