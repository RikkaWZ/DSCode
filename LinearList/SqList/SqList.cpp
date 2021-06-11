#include "SqList.h"
/**
 * 王道P17.1
 * 删除具有最小值的元素，空出的位置由最后一个元素填补
 */
bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0)
        return false;
    value = L.data[0]; // 最小值先当作是第一个元素
    int pos = 0;
    for (int i = 1; i < L.length; i++)
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

/**
 * 王道P17.2
 * 设计高效算法逆置顺序表，时间复杂度 O(1)
 */
void Reverse(SqList &L) {
    ElemType temp;
    // 遍历表前半部分，与后半部分逐一交换顺序
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

/**
 * 王道P17.3
 * 删除表中所有值为 x 的数据元素
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */
void Del_x_1(SqList &L, ElemType x) {
    // 解法1
    int k = 0; // 记录值不为 x 的元素个数
    for (int i = 0; i < L.length; i++)
        // 边扫描边统计 k，并将不等于 x 的元素向前移动 k 个位置
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    L.length = k; // 最后修改长度
}
void Del_x_2(SqList &L, ElemType x) {
    // 解法2
    int k = 0; // 记录值为 x 的元素个数
    int i = 0;
    while (i < L.length) {
        // 边扫描边统计 k，并将不等于 x 的元素向前移动 k 个位置
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i];
        i++;
    }
    L.length -= k; // 最后修改长度
}

/**
 * 王道P17.5
 * 删除顺序表表中所有值在给定值 s 与 t 之间的所有元素
 */
bool Del_x_t(SqList &L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return false;
    int k = 0; // 记录值在 s 与 t 之间的元素个数
    for (int i = 0; i < L.length; i++) {
        // 边扫描边统计 k，并将不等于 x 的元素向前移动 k 个位置
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i];
    }
    L.length -= k; // 最后修改长度
    return true;
}

/**
 * 王道P17.4
 * 删除*有序*顺序表表中所有值在给定值 s 与 t 之间的所有元素
 */
bool Del_x_t_2(SqList &L, ElemType s, ElemType t) {
    int i;
    int j;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.data[i] < s; i++); // 寻找大于等于 s 的第一个元素
    if (i >= L.length)
        // 所有元素都小于 s
        return false;
    for (j = i; i < L.length && L.data[i] <= t; j++); // 寻找大于 t 的第一个元素
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j]; // 前移，填充被删元素位置
    L.length = i;
    return true;
}

/**
 * 王道P17.6
 * 有序顺序表删除所有值重复的元素，使表中元素均不同
 */
bool Del_Same(SqList &L) {
    if (L.length == 0)
        return false;
    int i = 0; // 存储第一个不相同的元素指针
    for (int j = 1; j < L.length; j++)
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    L.length = i + 1;
    return true;
}

/**
 * 王道P17.7
 * 两个有序表合成一个新的有序表
 */
bool Merge(SqList &A, SqList &B, SqList &C) {
    if (A.length + B.length > MaxSize)
        return false;
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

int main() {
    SqList L;
    InitList(L);
//    IncreaseSize(L, 5);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    int d = 0;
    ListDelete(L, 1, d);

    ListInsert(L, 2, 9);
    printf("%d", LocateElem(L, 9));
    return 0;
}
