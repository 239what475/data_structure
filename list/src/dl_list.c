//
// Created by zhuzh on 2022/6/16.
//

#include "dl_list.h"

Status ListInsert_DuL(DuLinkList *L, int i, ElemType e) {
    DuLNode *p = GetElemP_Dul(L, i);
    if (!p) return ERROR;
    DuLNode *s = (DuLinkList) malloc(sizeof(DuLNode));
    if (!s) exit(OVERFLOW);
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

DuLNode *GetElemP_Dul(DuLinkList *L, int i) {
    DuLNode *p = (*L)->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}

Status ListDelete_Dul(DuLinkList *L, int i, ElemType *e) {
    DuLNode *p = GetElemP_Dul(L, i);
    if (!p) return ERROR;
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
