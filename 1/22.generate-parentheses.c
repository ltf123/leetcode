/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//卡特兰数老是忘，还得好好学学，还有就是递归是一个到底才执行另一个
#include <stdlib.h>
#include <string.h>
void generate(char** parenthesis, int* n, int left, int right, char* s, int index)
{
    if (left == 0 && right == 0) {
        strcpy(parenthesis[*n], s);
        (*n)--;
    }
    if (left > 0) {
        s[index] = '(';
        generate(parenthesis, n, left - 1, right, s, index + 1);
    }
    if (right > 0 && right > left) {
        s[index] = ')';
        generate(parenthesis, n, left, right - 1, s, index + 1);
    }
}
char** generateParenthesis(int n, int* returnSize)
{
    int factorial = 1;
    int temp = 1;
    int tmep = n;
    for (int i = 2 * n; i > n; i--) {
        factorial *= i;
        temp *= tmep;
        tmep--;
    }
    factorial = factorial / (n + 1);
    factorial = factorial / temp;
    *returnSize = factorial;
    char** parenthesis = (char**)malloc(sizeof(char**) * factorial);
    for (int index = 0; index < factorial; index++) {
        parenthesis[index] = (char*)malloc(sizeof(char) * (2 * n + 1));
        memset(parenthesis[index], 0, 2 * n + 1);
    }
    char* s = (char*)malloc(sizeof(char) * (2 * n + 1));
    memset(s, 0, 2 * n + 1);
    factorial--;
    generate(parenthesis, &factorial, n, n, s, 0);
    return parenthesis;
}
