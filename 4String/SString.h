#define MAXLEN 255

/**
 * 串（顺序存储）
 */
typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

/**
 * 求子串
 */
bool SubString(SString &Sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length)
        // 子串范围越界
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

/**
 * 比较两个串的大小
 */
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length; // 扫描的所有字符相同，长度长的更大
}

/**
 * 定位
 */
int Index(SString S, SString T) {
    int i = 1;
    int n = S.length;
    int m = T.length;
    SString sub; // 暂存子串
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) ++i;
        else return i;
    }
    return  0; // S 中不存在与 T 相等的子串
}














