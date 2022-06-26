//
// Created by zhuzh on 2022/5/18.
//

#include "stdio.h"
#include "list_test.h"
#include "sq_list.h"
#include "l_list.h"
#include "sl_list.h"
#include "al_list.h"

Status compare(ElemType p, ElemType e) {
    if (p == e) return OK;
    else return ERROR;
}

__attribute__((unused)) void Test_Sq_List() {
    SqList sqList;
    InitList_Sq(&sqList);
    printf("init sq list success\n");
    ListDisplay_Sq(&sqList);
    printf("insert 123 at index 1\n");
    if (ListInsert_Sq(&sqList, 1, 123)) {
        ListDisplay_Sq(&sqList);
        printf("insert success\n");
        printf("Find123: %d\n", LocateElem_Sq(&sqList, 123, compare));
        ElemType e;
        printf("delete 123\n");
        ListDelete_Sq(&sqList, 1, &e);
        ListDisplay_Sq(&sqList);
        printf("Find123: %d\n", LocateElem_Sq(&sqList, 123, compare));
    } else {
        printf("insert item fail\n");
    }
    DestroyList_Sq(&sqList);

    SqList La, Lb, Lc;
    InitList_Sq(&La);
    ListInsert_Sq(&La, 1, 456);
    ListInsert_Sq(&La, 1, 123);
    ListDisplay_Sq(&La);

    InitList_Sq(&Lb);
    ListInsert_Sq(&Lb, 1, 345);
    ListInsert_Sq(&Lb, 1, 234);
    ListDisplay_Sq(&Lb);

    MergeList_Sq(&La, &Lb, &Lc);
    DestroyList_Sq(&La);
    DestroyList_Sq(&Lb);

    ListDisplay_Sq(&Lc);
    printf("list length: %d\n", ListLength_Sq(&Lc));

    ElemType e1;
    if (GetElem_Sq(&Lc, 3, &e1)) {
        printf("elem at index 3 : %d\n", e1);
    }
    if (PriorElem_Sq(&Lc, e1, &e1)) {
        printf("elem prior of 3: %d\n", e1);
    }
    if (NextElem_Sq(&Lc, e1, &e1)) {
        printf("elem next of 2: %d\n", e1);
    }

    printf("clear list\n");
    ClearList_Sq(&Lc);
    ListDisplay_Sq(&Lc);
    printf("is list empty ? %s\n", ListEmpty_Sq(&Lc) ? "true" : "false");

    DestroyList_Sq(&Lc);
}

__attribute__((unused)) void Test_Link_List() {
    LinkList La, Lb, Lc;
    InitList_L(&La, (int[]) {1, 2, 3}, 3);
    InitList_L(&Lb, (int[]) {0, 6, 9}, 3);
    ListDisplay_L(&La);
    ListDisplay_L(&Lb);

    MergeList_L(&La, &Lb, &Lc);
    ListDisplay_L(&Lc);

    ElemType i;
    GetElem_L(&Lc, 4, &i);
    printf("get elem at index 4: %d\n", i);

    printf("insert 1 at index 5\n");
    ListInsert_L(&Lc, 5, 1);
    ListDisplay_L(&Lc);

    printf("delete elem at index 2\n");
    ListDelete_L(&Lc, 2, NULL);
    ListDisplay_L(&Lc);

    printf("list length: %d\n", ListLength_L(&Lc));

    printf("9 at index %d\n", LocateElem_L(&Lc, 9, compare));
    printf("find 123 ? %s\n", LocateElem_L(&Lc, 123, compare) ? "yes" : "no");

    ElemType e;
    PriorElem_L(&Lc, 9, &e);
    printf("prior of 9 : %d\n", e);
    printf("any elem prior of 0 : %s\n", PriorElem_L(&Lc, 0, NULL) ? "yes" : "no");
    NextElem_L(&Lc, 0, &e);
    printf("next elem of 0 : %d\n", e);

    printf("clear link list\n");
    ClearList_L(&Lc);
    ListDisplay_L(&Lc);

    printf("is list empty: %s\n", ListEmpty_L(&Lc) ? "true" : "false");

    DestroyList_L(&Lc);
}

__attribute__((unused)) void Test_SLink_List() {
    SLinkList L;
    InitSpace_SL(&L);
    ListDisplay_SL(&L);
    difference(&L);
    ListDisplay_SL(&L);
}

Status add1(ElemType *e) {
    *e += 1;
    return OK;
}

int max(ElemType a, ElemType b) {
    return a < b;
}

__attribute__((unused)) void Test_ALink_List() {
    ALinkList *La = NULL;
    InitList_AL(&La);
    ListDisplay_AL(La);
    ALink a;
    MakeNode_AL(&a, 1);
    printf("insert a at first \n");
    InsFirst_AL(La, a);
    ListDisplay_AL(La);

    printf("insert at 2 \n");
    ListInsert_AL(La, 2, 2);
    ListDisplay_AL(La);

    printf("insert before a \n");
    ALink b;
    MakeNode_AL(&b, 3);
    InsBefore_AL(La, &a, b);
    ListDisplay_AL(La);

    printf("is node before a(=b) ? %s \n", PriorPos_AL(La, a) ? "yes" : "no");

    printf("insert after a \n");
    ALink c;
    MakeNode_AL(&c, 4);
    InsAfter_AL(La, &a, c);
    ListDisplay_AL(La);

    printf("set a(=c) next node data = 5 \n");
    c = NextPos_AL(La, a);
    SetCurElem_AL(&c, 5);
    ListDisplay_AL(La);

    printf("remove last :");
    ALink q;
    Remove_AL(La, &q);
    printf("%d \n", q->data);
    ListDisplay_AL(La);

    printf("locate elem 3 at :");
    c = LocateElem_AL(La, 5, compare);
    printf("%p \n", c);

    printf("each elem add 1 \n");
    ListTraverse_AL(La, add1);
    ListDisplay_AL(La);

    printf("\n\n\n");
    printf("La:\n");
    ListDisplay_AL(La);
    ALinkList *Lb = NULL, *Lc = NULL;
    InitList_AL(&Lb);
    ListInsert_AL(Lb, 1, 1);
    printf("Lb:\n");
    ListDisplay_AL(Lb);
    MergeList_AL(La, Lb, &Lc, max);
    printf("merge La and Lb to Lc:\n");
    ListDisplay_AL(Lc);
    printf("\n\n\n");

    printf("clear link list\n");
    ClearList_AL(La);
    ListDisplay_AL(La);

    DestroyList_AL(&La);
}

