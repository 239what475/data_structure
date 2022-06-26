//
// Created by zhuzh on 2022/6/24.
//

#ifndef DATA_STRUCTURE_L_QUEUE_H
#define DATA_STRUCTURE_L_QUEUE_H

#include "common.h"

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode , *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue_L(LinkQueue *Q);

Status DestroyQueue_L(LinkQueue *Q);

Status ClearQueue_L(LinkQueue *Q);

bool QueueEmpty_L(LinkQueue *Q);

int QueueLength_L(LinkQueue *Q);

Status QueueDisplay_L(LinkQueue *Q);

Status GetHead_L(LinkQueue *Q,ElemType *e);

Status EnQueue_L(LinkQueue *Q,ElemType e);

Status DeQueue_L(LinkQueue *Q,ElemType *e);

Status QueueTraverse_L(LinkQueue *Q,void visit());

#endif //DATA_STRUCTURE_L_QUEUE_H
