//
// Created by zhuzh on 2022/6/26.
//

#include "c_queue.h"

Status InitQueue_C(CircleQueue *Q) {
    Q->base = (ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
    if (!Q->base) exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
}

Status DestroyQueue_C(CircleQueue *Q) {
    if (!Q->base) return ERROR;
    free(Q->base);
    Q->base = NULL;
    return OK;
}

Status ClearQueue_C(CircleQueue *Q) {
    if (!Q->base) return ERROR;
    Q->front = Q->rear = 0;
    return OK;
}

bool QueueEmpty_C(CircleQueue *Q) {
    return Q->front == Q->rear;
}

int QueueLength_C(CircleQueue *Q) {
    return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

Status QueueDisplay_C(CircleQueue *Q) {
    if (!Q->base) return ERROR;
    printf("-------------------------------\n");
    int length = QueueLength_C(Q);
    printf("size: %d\n", length);
    printf("[");
    for (int i = 0; i < length; ++i) {
        printf("%d", Q->base[(Q->front + i) % MAXQSIZE]);
        if (i < length - 1) printf("->");
    }
    printf("]\n");
    printf("-------------------------------\n");
    return OK;
}

Status GetHead_C(CircleQueue *Q, int *e) {
    if (Q->front == Q->rear) return ERROR;
    *e = Q->base[Q->front];
    return OK;
}

Status EnQueue_C(CircleQueue *Q, int e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front) return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue_C(CircleQueue *Q, int *e) {
    if (Q->front == Q->rear) return ERROR;
    if(e) *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

Status QueueTraverse_C(CircleQueue *Q, void (*visit)()) {
    if (!Q->base) return ERROR;
    for (int i = 0; i < QueueLength_C(Q); ++i) {
        visit();
    }
    return OK;
}
