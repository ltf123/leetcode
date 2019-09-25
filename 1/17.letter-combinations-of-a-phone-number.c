/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/262920/4ms-pure-C
//照着上面那个地址的答案写的，还是不是太理解，大致理解是，每次计算一个字母可以连续重复的次数，对于第一个位置
//上的字母，当后面可以给出n中不同的组合时，那么它可以连续重复n次。希望有人能给出证明
#include <stdlib.h>
#include <string.h>
char** letterCombinations(char* digits, int* returnSize)
{
    char temp[9][5] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    int len = strlen(digits);
    if (digits == NULL || len == 0) {
        *returnSize = 0;
        return NULL;
    }
    int size = 1;
    int cursor = 0;
    int repeatTimes, stringLen;
    for (int i = 0; i < len; i++) {
        size *= strlen(temp[digits[i] - '1']);
    }
    repeatTimes = size;
    *returnSize = size;
    char** result = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    for (int i = 0; i <= len; i++) {
        if (i < len) {
            stringLen = strlen(temp[digits[i] - '1']);
            repeatTimes /= stringLen;
        }
        for (int j = 0; j < size; j++) {
            if (i == len) {
                result[j][i] = '\0';
            } else {
                result[j][i] = temp[digits[i] - '1'][j / repeatTimes % stringLen];
            }
        }
    }
    return result;
}
