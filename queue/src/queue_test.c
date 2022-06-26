//
// Created by zhuzh on 2022/6/24.
//

#include "queue_test.h"
#include "l_queue.h"
#include "c_queue.h"

void print() {
    printf("show elem\n");
}

__attribute__((unused)) void Test_Link_Queue() {
    LinkQueue Q;
    InitQueue_L(&Q);
    QueueDisplay_L(&Q);

    EnQueue_L(&Q,10);
    EnQueue_L(&Q,20);
    EnQueue_L(&Q,30);
    QueueDisplay_L(&Q);
    QueueTraverse_L(&Q,print);
    ElemType head;
    GetHead_L(&Q,&head);
    printf("head of queue : %d \n",head);

    DeQueue_L(&Q,NULL);
    DeQueue_L(&Q,NULL);
    QueueDisplay_L(&Q);

    printf("clear queue:\n");
    ClearQueue_L(&Q);
    printf("queue empty ? %s \n", QueueEmpty_L(&Q) ? "yes" : "no");

    DestroyQueue_L(&Q);
}

__attribute__((unused)) void Test_Cir_Queue() {
    CircleQueue Q;
    InitQueue_C(&Q);
    QueueDisplay_C(&Q);

    EnQueue_C(&Q,10);
    EnQueue_C(&Q,20);
    EnQueue_C(&Q,30);
    QueueDisplay_C(&Q);
    QueueTraverse_C(&Q,print);
    ElemType head;
    GetHead_C(&Q,&head);
    printf("head of queue : %d \n",head);

    DeQueue_C(&Q,NULL);
    DeQueue_C(&Q,NULL);
    QueueDisplay_C(&Q);

    printf("clear queue:\n");
    ClearQueue_C(&Q);
    printf("queue empty ? %s \n", QueueEmpty_C(&Q) ? "yes" : "no");

    DestroyQueue_C(&Q);
}
