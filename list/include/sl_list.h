//
// Created by zhuzh on 2022/5/24.
//

#ifndef DATA_STRUCTURE_SL_LIST_H
#define DATA_STRUCTURE_SL_LIST_H

#include "common.h"

#define MAXSIZE 10

__attribute__((unused)) typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

/**
 * 初始化备用空间
 * @param L 数组空间指针
 */
void InitSpace_SL(SLinkList *L);

/**
 * 分配空闲节点
 * @param L 数组空间指针
 * @return 空闲节点下标
 */
int Malloc_SL(SLinkList *L);

/**
 * 回收节点，并将数据设置为0，将节点拼接到头节点后方
 * @param L 数组空间指针
 * @param k 节点下标
 */
void Free_SL(SLinkList *L,int k);

/**
 * 例2.3 求(A-B)∪(B-A)
 * @param L 数组空间指针
 */
void difference(SLinkList *L);

/**
 * 输出完整数组
 * @param L 数组空间指针
 * @return OK
 */
Status ListDisplay_SL(SLinkList *L);

#endif //DATA_STRUCTURE_SL_LIST_H
