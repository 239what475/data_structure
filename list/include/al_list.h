//
// Created by zhuzh on 2022/6/17.
//

#ifndef DATA_STRUCTURE_AL_LIST_H
#define DATA_STRUCTURE_AL_LIST_H

#include "common.h"

typedef struct ALNode {
    ElemType data;
    struct ALNode *next;
} *ALink, ALNode;
// 保证链表的最后一个结点的 next 为 NULL

typedef struct {
    ALink head, tail;
    int len;
} ALinkList;

/**
 * 分配由 p 指向的值为 e 的结点
 * @param p 分配的节点的指针
 * @param e 值
 * @return OK / ERROR
 */
Status MakeNode_AL(ALink *p, ElemType e);

/**
 * 释放 p 指向的结点
 * @param p 结点指针
 */
void FreeNode_AL(ALink *p);

/**
 * 构造一个空的线性链表 L
 * @param L 链表指针
 * @return OK / ERROR
 */
Status InitList_AL(ALinkList **L);

/**
 * 销毁线性链表 L
 * @param L 链表指针
 * @return OK / ERROR
 */
Status DestroyList_AL(ALinkList **L);

/**
 * 输出链表
 * @param L 链表指针
 * @return OK
 */
Status ListDisplay_AL(ALinkList *L);

/**
 * 将线性链表 L 重置为空表，并释放原链表的结点空间
 * @param L 链表指针
 * @return OK / ERROR
 */
Status ClearList_AL(ALinkList *L);

/**
 * 将结点 s 插入到头结点之后
 * @param L 链表指针
 * @param s 新的结点
 * @return OK / ERROR
 */
Status InsFirst_AL(ALinkList *L, ALink s);

/**
 * 删除头结点后的第一个结点并返回
 * @param L 链表指针
 * @param q 被删除的结点
 * @return OK / ERROR
 */
Status DelFirst_AL(ALinkList *L, ALink *q);

/**
 * 将指针 s 所指的一串结点链接在线性链表 L 的最后一个结点，并改变链表 L 的尾指针指向新的尾节点
 * @param L 链表指针
 * @param s 新的结点
 * @return OK / ERROR
 */
Status Append_AL(ALinkList *L, ALink s);

/**
 * 删除线性链表 L 中的尾节点并以 q 返回，改变链表 L 的尾指针指向新的尾节点
 * @param L 链表指针
 * @param q 返回的尾节点
 * @return OK / ERROR
 */
Status Remove_AL(ALinkList *L, ALink *q);

/**
 * 已知 p 指向线性链表 L 中的一个结点，将 s 所指结点插入在 p 所指结点之前，并修改指针 p 指向新插入的结点
 * @param L 链表指针
 * @param p 结点指针
 * @param s 插入的结点
 * @return OK / ERROR
 */
Status InsBefore_AL(ALinkList *L, ALink *p, ALink s);

/**
 * 已知 p 指向线性链表 L 中的一个结点，将 s 所指结点插入在 p 所指结点之后，并修改指针 p 指向新插入的结点
 * @param L 链表指针
 * @param p 结点指针
 * @param s 插入的结点
 * @return OK / ERROR
 */
Status InsAfter_AL(ALinkList *L, ALink *p, ALink s);

/**
 * 已知 p 指向线性链表中的一个结点，用 e 更新 p 所指结点中数据元素的值
 * @param p 结点指针
 * @param e 新的值
 * @return OK / ERROR
 */
Status SetCurElem_AL(ALink *p, ElemType e);

/**
 * 已知 p 指向线性链表 L 中的一个结点，返回 p 所指结点中数据元素的值
 * @param p 结点指针
 * @return p 的值
 */
ElemType GetCurElem_AL(ALink p);

/**
 * 判断链表是否为空
 * @param L 链表指针
 * @return bool
 */
bool ListEmpty_AL(ALinkList *L);

/**
 * 返回链表中元素个数
 * @param L 链表指针
 * @return 列表长度
 */
int ListLength_AL(ALinkList *L);

/**
 * 返回线性链表 L 中第一个数据节点的指针
 * @param L 链表指针
 * @return 第一个数据结点指针
 */
ALink GetFirst_AL(ALinkList *L);

/**
 * 已知 p 指向线性链表 L 中的一个结点，返回 p 所指结点的直接前驱的指针或 NULL
 * @param L 链表指针
 * @param p 结点指针
 * @return 前驱结点指针
 */
ALink PriorPos_AL(ALinkList *L, ALink p);

/**
 * 已知 p 指向线性链表 L 中的一个结点，返回 p 所指结点的直接后继的指针或 NULL
 * @param L 链表指针
 * @param p 结点指针
 * @return 后继结点指针
 */
ALink NextPos_AL(ALinkList *L, ALink p);

/**
 * 返回线性链表 L 中第 i 个结点的指针
 * @param L 链表指针
 * @param i 结点位序
 * @param p 第 i 个结点的指针
 * @return OK / ERROR
 */
Status LocatePos_AL(ALinkList *L, int i, ALink *p);

/**
 * 返回线性链表 L 中第 1 个满足函数 compare() 判定关系的元素的指针，若不存在返回NULL
 * @param L 链表指针
 * @param compare 查询函数
 * @return 满足 compare() 的第一个元素的指针
 */
ALink LocateElem_AL(ALinkList *L,ElemType e, Status(*compare)(ElemType p,ElemType e));

/**
 * 依次对 L 的每个元素调用函数 visit() ，一旦 visit()失败，则操作失败
 * @param L 链表指针
 * @param visit 执行函数
 * @return OK / ERROR
 */
Status ListTraverse_AL(ALinkList *L, Status(*visit)(ElemType*));

/**
 * 在第 i 个元素之前插入元素
 * @param L 链表指针
 * @param i 插入位置
 * @param e 插入元素数据
 * @return OK / ERROR
 */
Status ListInsert_AL(ALinkList *L, int i, ElemType e);

/**
 * 合并两个链表 La，Lb 成第三个链表 Lc
 * @param La 链表指针
 * @param Lb 链表指针
 * @param Lc 合并结果链表指针
 * @param compare 比较函数
 * @return OK / ERROR
 */
Status MergeList_AL(ALinkList *La, ALinkList *Lb, ALinkList **Lc, int (*compare)(ElemType a, ElemType b));

#endif //DATA_STRUCTURE_AL_LIST_H
