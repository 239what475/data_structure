//
// Created by zhuzh on 2022/6/24.
//

#include "l_queue.h"

Status InitQueue_L(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front) exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue_L(LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    Q->front = Q->rear = NULL;
    return OK;
}

Status ClearQueue_L(LinkQueue *Q) {
    if (!Q->front) return ERROR;
    while (Q->front->next) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

bool QueueEmpty_L(LinkQueue *Q) {
    return Q->front == Q->rear;
}

int QueueLength_L(LinkQueue *Q) {
    int l = 0;
    QueuePtr p = Q->front;
    while ((p = p->next)) {
        l++;
    }
    return l;
}

Status GetHead_L(LinkQueue *Q, int *e) {
    if (!QueueEmpty_L(Q)) return ERROR;
    *e = Q->rear->data;
    return OK;
}

Status EnQueue_L(LinkQueue *Q, int e) {
    QueuePtr p = malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue_L(LinkQueue *Q, int *e) {
    if (Q->front == Q->rear) return ERROR;
    QueuePtr p = Q->front->next;
    if(e) *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    return OK;
}

Status QueueTraverse_L(LinkQueue *Q, void (*visit)()) {
    QueuePtr p = Q->front;
    if (!p) return ERROR;
    while ((p = p->next)) visit();
    return OK;
}

Status QueueDisplay_L(LinkQueue *Q) {
    if(!Q->front) return ERROR;
    printf("-------------------------------\n");
    printf("size: %d\n", QueueLength_L(Q));
    printf("[");
    QueuePtr p = Q->front->next;
    while (p) {
        printf("%d", p->data);
        if (p->next) printf("->");
        p = p->next;
    }
    printf("]\n");
    printf("-------------------------------\n");
    return OK;
}
