/*
 * @lc app=leetcode id=56 lang=c
 *
 * [56] Merge Intervals
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// c 语言指针太复杂了， 我哭了。。。。
int compare(const void* a, const void* b)
{
    return (*((int**)a))[0] > (*((int**)b))[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        int** rintervals = NULL;
        return rintervals;
    }
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    int flag = 0;
    *returnSize = 0;
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    for (int i = 0; i < intervalsSize; i++) {
        if (flag == 0) {
            flag = 1;
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
        }
        if (intervals[i][0] <= result[*returnSize][1] && intervals[i][1] > result[*returnSize][1]) {
            result[*returnSize][1] = intervals[i][1];
        }
        if (intervals[i][0] > result[*returnSize][1]) {
            *returnSize += 1;
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
        }
    }
    *returnColumnSizes = intervalsColSize;
    *returnSize += 1;
    return result;
}

// @lc code=end
