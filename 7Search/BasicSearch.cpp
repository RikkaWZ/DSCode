#include "../2LinearList/SqList/DynamicSqList.h"

/**
 * 顺序查找
 */
int SeqSearch(SqList L, ElemType key) {
    L.data[0] = key; // 哨兵
    int i;
    for (i = L.length; L.data[i] != key; i--); // 从后往前遍历
    return i; // 查找失败是返回 0
}

/**
 * 二分查找
 */
int BinarySearch(SqList L, ElemType key) {
    int low = 0;
    int high = L.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
            return mid;
        else if (L.data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}