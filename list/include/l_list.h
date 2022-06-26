//
// Created by zhuzh on 2022/5/21.
//

#ifndef DATA_STRUCTURE_L_LIST_H
#define DATA_STRUCTURE_L_LIST_H

#include "common.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 构造一个包含数据的链式线性表
 * @param L 链式线性表头指针的指针
 * @param elem 数据数组
 * @param n 数组长度
 */
void InitList_L(LinkList* L,const ElemType * elem,int n);

/**
 * 销毁链式线性表
 * @param L 链式线性表指针
 */
void DestroyList_L(LinkList* L);

/**
 * 清空链式线性表
 * @param L 链式线性表指针
 * @return success -> OK / 链式线性表未初始化 -> ERROR
 */
Status ClearList_L(LinkList* L);

/**
 * 判断链式线性表是否为空
 * @param L 链式线性表头指针的指针
 * @return 链式线性表为空 -> true / 不为空 -> false
 */
bool ListEmpty_L(LinkList* L);

/**
 * 获取链式线性表长度
 * @param L 链式线性表头指针的指针
 * @return L.length
 */
int ListLength_L(LinkList* L);

/**
 * 获取指定位序上的元素
 * @param L 链式线性表头指针的指针
 * @param i 位序
 * @param e 返回值指针
 * @return success -> OK / i 超出范围 -> ERROR
 */
Status GetElem_L(LinkList* L, int i, ElemType *e);

/**
 * 查找符合条件的第一个元素
 *
 * 书上P25定义：int LocateElem_L(LinkList *L, ElemType e, Status(*compare)(ElemType, ElemType));
 * 但我认为并不需要传入参数e
 *
 * @param L 链式线性表头指针的指针
 * @param compare 查询函数指针
 * @return find -> index / else -> 0
 */
int LocateElem_L(LinkList* L,ElemType e, Status(*compare)(ElemType,ElemType));

/**
 * 返回匹配的元素的前一个元素
 * @param L 链式线性表头指针的指针
 * @param cur_e 指定元素
 * @param pre_e 前一个元素的指针
 * @return success -> OK / 无匹配元素或匹配第一个元素 -> ERROR
 */
Status PriorElem_L(LinkList* L,ElemType cur_e,ElemType *pre_e);

/**
 * 返回匹配的元素的后一个元素
 * @param L 链式线性表头指针的指针
 * @param cur_e 指定元素
 * @param next_e 后一个元素的指针
 * @return success -> OK / 无匹配元素或匹配最后一个元素 -> ERROR
 */
Status NextElem_L(LinkList* L,ElemType cur_e,ElemType *next_e);

/**
 * 插入元素
 * @param L 链式线性表头指针的指针
 * @param i 插入位置（第 i 个之前）
 * @param e 要插入的元素
 * @return OK/ERROR
 */
Status ListInsert_L(LinkList* L, int i, ElemType e);

/**
 * 删除并返回元素
 * @param L 链式线性表头指针的指针
 * @param i 删除的元素的位序
 * @param e 返回值指针
 * @return OK/ERROR
 */
Status ListDelete_L(LinkList* L, int i, ElemType *e);

/**
 *  输出链式线性表
 * @param L 链式线性表头指针的指针
 * @return success -> OK / null pointer -> ERROR
 */
Status ListDisplay_L(LinkList* L);

/**
 * 已知链式线性表 La 和 Lb 的元素按值非递减排列，将其归并到 Lc。使 Lc 的元素也非递减排列。
 * 使用 La 的表头作为 Lc 的表头，并且合并完成后销毁 Lb 的表头
 * @param La 非递减链式线性表
 * @param Lb 非递减链式线性表
 * @param Lc 归并结果链式线性表
 */
void MergeList_L(LinkList* La, LinkList* Lb, LinkList* Lc);

#endif //DATA_STRUCTURE_L_LIST_H
