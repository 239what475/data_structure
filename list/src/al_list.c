//
// Created by zhuzh on 2022/6/17.
//

#include "al_list.h"

Status MakeNode_AL(ALink *p, ElemType e) {
    ALink l = malloc(sizeof(ALNode));
    if (!l) exit(OVERFLOW);
    l->data = e;
    l->next = NULL;
    *p = l;
    return OK;
}

void FreeNode_AL(ALink *p) {
    free(*p);
}

// TODO: 这里其实有问题，没必要手动分配 AlinkList的内存，只分配头结点就行，改为 ALinkList *L
Status InitList_AL(ALinkList **L) {
    // 防止重复初始化
    if (*L) return ERROR;
    ALinkList *l = malloc(sizeof(ALinkList));
    if (!l) exit(OVERFLOW);
    l->len = 0;
    MakeNode_AL(&l->head, 0);
    l->head->next = NULL;
    l->tail = l->head;
    *L = l;
    return OK;
}

Status DestroyList_AL(ALinkList **L) {
    // 不重复销毁
    if (!*L) return ERROR;
    ALink p = (*L)->head, q;
    while (p) {
        q = p->next;
        FreeNode_AL(&p);
        p = q;
    }
    free(*L);
    *L = NULL;
    return OK;
}

Status ListDisplay_AL(ALinkList *L) {
    if (!L) return ERROR;
    printf("-------------------------------\n");
    printf("len: %d\n", L->len);
    printf("[");
    ALink p = L->head->next;
    while (p) {
        printf("%d", p->data);
        if (p->next) printf("->");
        p = p->next;
    }
    printf("]\n");
    printf("-------------------------------\n");
    return OK;
}

Status ClearList_AL(ALinkList *L) {
    // 排除链表被销毁
    if (!L) return ERROR;
    ALink p = L->head->next, q;
    while (p) {
        q = p->next;
        FreeNode_AL(&p);
        p = q;
    }
    L->len = 0;
    L->head->next = NULL;
    L->tail = L->head;
    return OK;
}

Status InsFirst_AL(ALinkList *L, ALink s) {
    if (!L || !s) return ERROR;
    //将 s 插入到头结点之后
    s->next = L->head->next;
    L->head->next = s;
    // 如果链表为空，则插入结点 s 后需要改变链表的最后一个结点的指向
    if (ListEmpty_AL(L)) {
        L->tail = s;
        L->tail->next = NULL;
    }
    L->len += 1;
    return OK;
}

Status DelFirst_AL(ALinkList *L, ALink *q) {
    // 如果链表被销毁或为空
    if (!L || ListEmpty_AL(L)) return ERROR;
    *q = L->head->next;
    L->head->next = L->head->next->next;
    (*q)->next = NULL;
    // 如果链表长度为 1，则需要改变链表最后一个结点的指向
    if (ListLength_AL(L) == 1) {
        L->tail = L->head;
        L->tail->next = NULL;
    }
    L->len -= 1;
    return OK;
}

Status Append_AL(ALinkList *L, ALink s) {
    // 排除空结点和链表销毁
    if (!s || !L) return ERROR;
    // 在链表尾部拼接结点 s
    L->tail->next = s;
    // 计算拼接的链表的长度，以及找到最后一个结点
    int plus = 1;
    while (s->next) {
        plus++;
        s = s->next;
    }
    L->len += plus;
    L->tail = s;
    L->tail->next = NULL;
    return OK;
}

Status Remove_AL(ALinkList *L, ALink *q) {
    // 排除链表销毁或者链表为空
    if (!L || ListEmpty_AL(L)) return ERROR;
    *q = L->tail;
    // 找到倒数第二个结点
    ALink p = L->head;
    while (p->next != L->tail) {
        p = p->next;
    }
    L->tail = p;
    L->tail->next = NULL;
    // 缩短链表长度
    L->len -= 1;
    return OK;
}

// 已知 p 为链表中的一个结点
Status InsBefore_AL(ALinkList *L, ALink *p, ALink s) {
    // 检查链表是否被销毁或 p 是否指向头结点
    if (!L || L->head == *p) return ERROR;
    ALink q = L->head;
    // 找到 p 的前一个结点 q
    while (q->next != *p) {
        q = q->next;
    }
    // 在 p 之前插入 s
    s->next = *p;
    q->next = s;
    // 并将 p 指向 s
    *p = s;
    // 增加链表长度
    L->len += 1;
    return OK;
}

// 已知 p 为链表中的一个结点
Status InsAfter_AL(ALinkList *L, ALink *p, ALink s) {
    // 检查链表是否被销毁
    if (!L) return ERROR;
    // 将结点拼接到 p 的后面
    s->next = (*p)->next;
    (*p)->next = s;
    // 如果 p 是最后一个结点，则插入结点后需要改变链表的最后一个结点的指向
    if (*p == L->tail) {
        L->tail = s;
        L->tail->next = NULL;
    }
    // 并将 p 指向结点 s
    *p = s;
    // 增加链表长度
    L->len += 1;
    return OK;
}

Status SetCurElem_AL(ALink *p, ElemType e) {
    if (!(*p)) return ERROR;
    (*p)->data = e;
    return OK;
}

ElemType GetCurElem_AL(ALink p) {
    return p->data;
}

bool ListEmpty_AL(ALinkList *L) {
    return L->len == 0;
}

int ListLength_AL(ALinkList *L) {
    return L->len;
}

ALink GetFirst_AL(ALinkList *L) {
    return L->head->next;
}

// 已知 p 为链表中的一个结点
ALink PriorPos_AL(ALinkList *L, ALink p) {
    // 检查链表是否被销毁或 p 为头结点
    if (!L || L->head == p) return NULL;

    ALink h = L->head;
    // 找到 p 的前一个结点
    while (h->next != p) {
        h = h->next;
    }

    if (L->head == h) return NULL;
    else return h;
}

ALink NextPos_AL(ALinkList *L, ALink p) {
    // 如果 p 是最后一个结点，则返回 NULL
    if (L->tail == p) return NULL;
    // 否则返回下一个结点
    return p->next;
}

Status LocatePos_AL(ALinkList *L, int i, ALink *p) {
    if (!L->head || i < L->len) return ERROR;
    int index = 0;
    ALink q = L->head;
    // 找到第 i 个结点
    while (index < i) {
        q = q->next;
        index++;
    }
    *p = q;
    return OK;
}

ALink LocateElem_AL(ALinkList *L, ElemType e, Status (*compare)(ElemType p, ElemType e)) {
    // 排除被销毁的链表和空链表
    if (!L->head || !L->head->next) return NULL;
    ALink p = L->head->next;
    while (p && !(*compare)(p->data, e)) {
        p = p->next;
    }
    return p;
}

Status ListTraverse_AL(ALinkList *L, Status (*visit)(ElemType *)) {
    // 排除被销毁的链表和空链表
    if (!L->head || !L->head->next) return ERROR;
    ALink p = L->head->next;
    while (p) {
        if ((*visit)(&p->data)) {
            p = p->next;
        } else {
            return ERROR;
        }
    }
    return OK;
}

Status ListInsert_AL(ALinkList *L, int i, ElemType e) {
    ALink h, s;
    // 对于从第 i 个结点开始的链表，第 i-1 个结点是它的头结点
    // 先找到前一个结点
    if (!LocatePos_AL(L, i - 1, &h)) return ERROR;
    if (!MakeNode_AL(&s, e)) return ERROR;
    // 在第 i-1 个结点后插入新的结点
    InsAfter_AL(L, &h, s);
    return OK;
}

Status MergeList_AL(ALinkList *La, ALinkList *Lb, ALinkList **Lc, int (*compare)(ElemType a, ElemType b)) {
    if (!InitList_AL(Lc)) return ERROR;
    // 获取第一个数据结点
    ALink pa = GetFirst_AL(La), pb = GetFirst_AL(Lb), q;
    // 对 La 和 Lb 进行遍历，每次向 Lc 中添加一个结点
    while (pa && pb) {
        // 获取当前数据
        ElemType a = GetCurElem_AL(pa), b = GetCurElem_AL(pb);
        // 比较并向 Lc 中添加结点
        if ((*compare)(a, b) <= 0) {
            DelFirst_AL(La, &q);
            Append_AL(*Lc, q);
            pa = GetFirst_AL(La);
        } else {
            DelFirst_AL(Lb, &q);
            Append_AL(*Lc, q);
            pa = GetFirst_AL(Lb);
        }
    }
    // 添加最后一个结点
    if (pa)Append_AL(*Lc, pa);
    else Append_AL(*Lc, pb);
    return OK;
}
