//
// Created by zhuzh on 2022/5/24.
//

#include "sl_list.h"

void InitSpace_SL(SLinkList *L) {
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        (*L)[i].cur = i + 1;
        (*L)[i].data = 0;
    }
    (*L)[MAXSIZE - 1].cur = 0;
}

Status ListDisplay_SL(SLinkList *L) {
    printf("-----------------------------------\n");
    for (int j = 0; j < MAXSIZE; ++j) {
        printf("[data: %d, index: %d, to: %d]\n", (*L)[j].data, j, (*L)[j].cur);
    }
    printf("-----------------------------------\n");
    return OK;
}

// 分配空白节点
int Malloc_SL(SLinkList *L) {
    // 获取头节点指向的第一个节点
    int i = (*L)[0].cur;
    // 如果第一个节点不是头节点，则将这个节点从链表中取出来
    if (i) (*L)[0].cur = (*L)[i].cur;
    // 返回这个节点的位置
    return i;
}

void Free_SL(SLinkList *L, int k) {
    // 将下标为k的节点拼接到头节点后
    (*L)[k].cur = (*L)[0].cur;
    (*L)[k].cur = 0;
    (*L)[0].cur = k;
}

void difference(SLinkList *L) {
    // 先分配一个节点，S为节点的下标
    int S = Malloc_SL(L);
    // m，n为A，B的元素个数
    int m = 0, n = 0;
    printf("A length: ");
    scanf("%d", &m);
    printf("B length: ");
    scanf("%d", &n);
    // 建立集合A的链表，将S作为A的头节点
    int r = S;
    for (int j = 1; j <= m; ++j) {
        // 分配节点，并存储值
        int i = Malloc_SL(L);
        scanf("%d", &(*L)[i].data);
        printf("(%d) = %d\n", j, (*L)[i].data);
        // 将新节点拼接到上一个节点后
        (*L)[r].cur = i;
        // 指向下一个节点
        r = i;
    }
    // 将尾节点的指示器设为0
    (*L)[r].cur = 0;

    ListDisplay_SL(L);

    // 输入集合B
    for (int j = 1; j <= n; ++j) {
        int b = 0;
        scanf("%d", &b);
        printf("(%d) = %d\n", j, b);
        // S为A的头节点
        int p = S;
        // k为A的第一个数据节点
        int k = (*L)[S].cur;
        // r是A的最后一个节点
        // 如果输入的值在A中，则返回节点下标；如果不在A中，则 k=0
        // k为p的下一个节点，k指向当前节点
        while (k != (*L)[r].cur && (*L)[k].data != b) {
            p = k;
            k = (*L)[k].cur;
        }
        if (k == (*L)[r].cur) {
            // 如果不在A中，则分配节点将这个值存起来，并添加到A的链表最后，B其他元素之前
            // 也就是说结果在列表中A顺序，B倒叙
            int i = Malloc_SL(L);
            (*L)[i].data = b;
            (*L)[i].cur = (*L)[r].cur;
            (*L)[r].cur = i;
        } else {
            // 如果在A中，则删除当前节点
            (*L)[p].cur = (*L)[k].cur;
            Free_SL(L, k);
            // 如果删除的是原本A链表的尾节点，则现在的尾节点是上一个节点，即为p
            if (r == k) r = p;
        }
    }
}