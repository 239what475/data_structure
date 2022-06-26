//
// Created by zhuzh on 2022/6/16.
//

#ifndef DATA_STRUCTURE_DL_LIST_H
#define DATA_STRUCTURE_DL_LIST_H

#include "common.h"

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

Status ListInsert_DuL(DuLinkList *L,int i,ElemType e);

DuLNode * GetElemP_Dul(DuLinkList * L, int i);

Status ListDelete_Dul(DuLinkList *L,int i,ElemType *e);

#endif //DATA_STRUCTURE_DL_LIST_H
