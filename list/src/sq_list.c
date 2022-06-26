//
// Created by zhuzh on 2022/5/18.
//

#include "sq_list.h"
#include "stdlib.h"
#include "stdio.h"

void InitList_Sq(SqList *L) {
    // https://blog.csdn.net/kakahaoma/article/details/87874947
    // difference between malloc and realloc
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)exit(OVERFLOW);
    L->length = 0;
    L->size = LIST_INIT_SIZE;
}

void DestroyList_Sq(SqList *L) {
    if (!L->elem) free(L->elem);
    L->length = 0;
    L->size = 0;
}

Status ClearList_Sq(SqList *L) {
    if (!L->elem) return ERROR;
    L->length = 0;
    return OK;
}

bool ListEmpty_Sq(SqList *L) {
    if (L->length == 0) return true;
    else return false;
}

int ListLength_Sq(SqList *L) {
    return L->length;
}

Status GetElem_Sq(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    int i = 0;
    while (++i <= L->length && !(*compare)(L->elem[i - 1], e)) break;
    if (i <= L->length) return i;
    else return 0;
}

Status PriorElem_Sq(SqList *L, ElemType cur_e, ElemType *pre_e) {
    int i = 1;
    while (i <= L->length && L->elem[i - 1] != cur_e) i++;
    printf("%d\n", i);
    if (i == 1 || i > L->length) return ERROR;
    *pre_e = L->elem[i - 2];
    return OK;
}

Status NextElem_Sq(SqList *L, ElemType cur_e, ElemType *next_e) {
    int i = 0;
    while (i < L->length && L->elem[i - 1] != cur_e) i++;
    if (i >= L->length) return ERROR;
    *next_e = L->elem[i];
    return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= L->size) {
        ElemType *newBase;
        newBase = (ElemType *) realloc(L->elem, (L->size + LIST_INCREMENT) * sizeof(ElemType));
        if (!newBase)exit(OVERFLOW);
        L->elem = newBase;
        L->size += LIST_INCREMENT;
    }
    ElemType *q = &L->elem[i - 1];
    for (ElemType *p = &L->elem[L->length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;
    return OK;
}

Status ListDisplay_Sq(SqList *L) {
    printf("SqList:{\n");
    printf("  elem: [");
    for (int i = 0; i < L->length; ++i) {
        printf("%d", L->elem[i]);
        if (i < L->length - 1) printf(",");
    }
    printf("]\n");
    printf("  length: %d\n", L->length);
    printf("  size: %d\n", L->size);
    printf("}\n");
    return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    ElemType *p = &L->elem[i - 1];
    // 修改指针指向的值
    if (e) *e = *p;
    ElemType *q = L->elem + L->length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L->length;
    return OK;
}

void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc) {
    ElemType *pa, *pb, *pc;
    pa = La->elem;
    pb = Lb->elem;
    Lc->size = Lc->length = La->length + Lb->length;
    pc = Lc->elem = (ElemType *) malloc(Lc->size * sizeof(ElemType));
    if (!Lc->elem) exit(OVERFLOW);
    ElemType *pa_last, *pb_last;
    pa_last = La->elem + La->length - 1;
    pb_last = Lb->elem + Lb->length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while (pa <= pa_last)*pc++ = *pa++;
    while (pb <= pb_last)*pc++ = *pb++;
}
