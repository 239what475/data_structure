//
// Created by zhuzh on 2022/5/21.
//

#include "l_list.h"

void InitList_L(LinkList *L, const ElemType *elem, int n) {
    *L = (LinkList) malloc(sizeof(LNode));
    if(!(*L)) exit(OVERFLOW);
    (*L)->next = NULL;
    for (int i = n; i > 0; --i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        if (!p) exit(OVERFLOW);
        p->data = elem[i - 1];
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void DestroyList_L(LinkList *L) {
    LNode *p = *L, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
}

Status ClearList_L(LinkList *L) {
    if (!*L) return ERROR;
    LNode *p = (*L)->next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

bool ListEmpty_L(LinkList *L) {
    return (*L)->next == NULL;
}

int ListLength_L(LinkList *L) {
    LNode *p = (*L)->next;
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

Status GetElem_L(LinkList *L, int i, ElemType *e) {
    LNode *p = (*L)->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

int LocateElem_L(LinkList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    LNode *p = (*L)->next;
    int l = 1;
    while (p && !(*compare)(p->data, e)) {
        l++;
        p = p->next;
    }
    if (p) return l;
    else return 0;
}

Status PriorElem_L(LinkList *L, ElemType cur_e, ElemType *pre_e) {
    LNode *p = (*L)->next, *q = NULL;
    while (p && p->data != cur_e) {
        q = p;
        p = p->next;
    }
    if (p && q) {
        if (pre_e) *pre_e = q->data;
        return OK;
    } else return ERROR;
}

Status NextElem_L(LinkList *L, ElemType cur_e, ElemType *next_e) {
    LNode *p = (*L)->next, *q = NULL;
    while (p && p->data != cur_e) {
        p = p->next;
    }
    if (p) q = p->next;
    if (q) {
        if (next_e) *next_e = q->data;
        return OK;
    } else return ERROR;
}

Status ListInsert_L(LinkList *L, int i, ElemType e) {
    LNode *p = *L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDisplay_L(LinkList *L) {
    printf("[");
    if (!*L) return ERROR;
    LNode *p = (*L)->next;
    while (p) {
        printf("%d", p->data);
        if (p->next) printf("->");
        p = p->next;
    }
    printf("]\n");
    return OK;
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
    LinkList pa, pb, pc;
    pa = (*La)->next;
    pb = (*Lb)->next;
    *Lc = pc = *La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(*Lb);
}

Status ListDelete_L(LinkList *L, int i, ElemType *e) {
    LNode *p = *L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i - 1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    if (e) *e = q->data;
    free(q);
    return OK;
}


