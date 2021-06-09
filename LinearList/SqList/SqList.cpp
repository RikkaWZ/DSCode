#include "SqList.h"

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
