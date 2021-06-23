#include "SString.h"

/**
 * 模式匹配
 */

/**
 * 朴素模式匹配
 */
int regularMatch(SString S, SString T) {
    int i = 1;
    int j = 1;
    while (i <= S.length && j < T.length) {
        if (S.ch[i] == T.ch[i]) {
            i++;
            j++;
        } else {
            // 两指针指向字符不同，后退重新开始匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

/**
 * KMP 算法模式匹配
 */
int KMPMatch(SString S, SString T, int next[]) {
    int i = 1;
    int j = 1;
    while (i <= S.length && j < T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}










