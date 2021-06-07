#include "stdlib.h"
#include "stdio.h"
#include "StaticSqList.h"

bool ListInsert(SqList &L, int i, ElemType e) {
    // 判断 i 的范围是否有效
    if (i < 1 || i > L.length + 1)
        return false;
    // 判断存储空间是否满了
    if (L.length >= MaxSize)
        return false;
    // 将第 i 个元素及其之后的元素后移
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1 ] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

/**
 * 按位查找，返回值
 */
ElemType GetElem(SqList L, int i) {
    return L.data[i - 1];
}

/**
* 按值查找，返回位序
 *
*/
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}
