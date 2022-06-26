//
// Created by zhuzh on 2022/5/16.
//

#ifndef DATA_STRUCTURE_SQ_LIST_H
#define DATA_STRUCTURE_SQ_LIST_H

#include "common.h"

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

/**
 * 顺序线性表 \n\n
 * elem: 元素数组 \n
 * length: 当前长度 \n
 * size: 当前分配的存储容量（以sizeof(ElemType)为单位）
 */
typedef struct {
    // 存储空间基址
    ElemType *elem;
    // 当前长度
    int length;
    // 当前分配的存储容量（以sizeof(ElemType)为单位）
    int size;
} SqList;

/**
 * 构造一个空的顺序线性表
 * @param L 顺序线性表指针
 */
void InitList_Sq(SqList *L);

/**
 * 销毁顺序线性表
 * @param L 顺序线性表指针
 */
void DestroyList_Sq(SqList *L);

/**
 * 清空顺序线性表
 * @param L 顺序线性表指针
 * @return success -> OK / 顺序线性表未初始化 -> ERROR
 */
Status ClearList_Sq(SqList *L);

/**
 * 判断顺序线性表是否为空
 * @param L 顺序线性表指针
 * @return 顺序线性表为空 -> true / 不为空 -> false
 */
bool ListEmpty_Sq(SqList *L);

/**
 * 获取顺序线性表长度
 * @param L 顺序线性表指针
 * @return L.length
 */
int ListLength_Sq(SqList *L);

/**
 * 获取指定位序上的元素
 * @param L 顺序线性表指针
 * @param i 位序
 * @param e 返回值指针
 * @return success -> OK / i 超出范围 -> ERROR
 */
Status GetElem_Sq(SqList *L, int i, ElemType *e);

/**
 * 查找符合条件的第一个元素
 *
 * 书上P25定义：int LocateElem_Sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType));
 * 但我认为并不需要传入参数e
 *
 * @param L 顺序线性表指针
 * @param compare 查询函数指针
 * @return find -> index / else -> 0
 */
int LocateElem_Sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType));

/**
 * 返回匹配的元素的前一个元素
 * @param L 顺序线性表指针
 * @param cur_e 指定元素
 * @param pre_e 前一个元素的指针
 * @return success -> OK / 无匹配元素或匹配第一个元素 -> ERROR
 */
Status PriorElem_Sq(SqList *L, ElemType cur_e, ElemType *pre_e);

/**
 * 返回匹配的元素的后一个元素
 * @param L 顺序线性表指针
 * @param cur_e 指定元素
 * @param next_e 后一个元素的指针
 * @return success -> OK / 无匹配元素或匹配最后一个元素 -> ERROR
 */
Status NextElem_Sq(SqList *L, ElemType cur_e, ElemType *next_e);

/**
 * 插入元素
 * @param L 顺序线性表指针
 * @param i 插入位置（第 i 个之前）
 * @param e 要插入的元素
 * @return OK/ERROR
 */
Status ListInsert_Sq(SqList *L, int i, ElemType e);

/**
 * 删除并返回元素
 * @param L 顺序线性表指针
 * @param i 删除的元素的位序
 * @param e 返回值指针
 * @return OK/ERROR
 */
Status ListDelete_Sq(SqList *L, int i, ElemType *e);

/**
 *  输出顺序线性表
 * @param L 顺序线性表指针
 */
Status ListDisplay_Sq(SqList *L);

/**
 * 已知顺序线性表 La 和 Lb 的元素按值非递减排列，将其归并到 Lc。使 Lc 的元素也非递减排列
 * @param La 非递减顺序线性表
 * @param Lb 非递减顺序线性表
 * @param Lc 归并结果顺序线性表
 */
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc);

#endif //DATA_STRUCTURE_SQ_LIST_H
