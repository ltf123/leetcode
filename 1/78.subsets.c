/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void search(int* nums, int numsSize, int* returnSize, int* returnColumnSizes, int size, int* re, int** result)
{
    if (numsSize <= 0) {
        return;
    }
    re[size] = *nums;
    size++;
    returnColumnSizes[*returnSize] = size;
    result[*returnSize] = (int*)malloc(size * sizeof(int));
    memcpy(result[*returnSize], re, size * sizeof(int));
    *returnSize = *returnSize + 1;
    for (int i = 1; i < numsSize; i++) {
        search(i + nums, numsSize - i, returnSize, returnColumnSizes, size, re, result);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

    *returnSize = (int)pow(2.0, numsSize * 1.0);
    int** result = (int**)malloc(*returnSize * sizeof(int*));
    int* re = (int*)malloc(numsSize * sizeof(int));
    int reSize = 0;
    int size = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int numsize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        search(nums, numsize, &reSize, *returnColumnSizes, size, re, result);
        ++nums;
        --numsize;
    }
    (*returnColumnSizes)[*returnSize - 1] = 0;
    return result;
}

// @lc code=end
