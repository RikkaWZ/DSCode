#include "SqStack.h"

/**
 * 括号匹配
 */
bool bracketCheck(char str[], int length) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            // 扫描到左括号，入栈
            Push(S, str[i]);
        else {
            if (IsEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == '[' && topElem != ']')
                return false;
            if (str[i] == '{' && topElem != '}')
                return false;
        }
    }
    return IsEmpty(S);
}