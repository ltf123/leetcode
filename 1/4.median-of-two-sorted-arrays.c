/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */
//草 这道题写了这么久，分支情况太多，写的提交了5次，才把分支全部搞对，擦，
int find(int* nums1, int nums1Size, int* nums2, int nums2Size, int index)
{
    if (nums1Size <= 0) {
        return nums2[index];
    }
    if (nums2Size <= 0) {
        return nums1[index];
    }
    int temp1 = nums1Size / 2;
    int temp2 = nums2Size / 2;
    int numNum = temp1 + temp2 + 1;
    if (numNum == index) {
        if (nums1[temp1] > nums2[temp2]) {
            return find(nums1, temp1 + 1, nums2 + temp2 + 1, nums2Size - temp2 - 1, index - temp2 - 1);
        } else {
            return find(nums1 + temp1 + 1, nums1Size - temp1 - 1, nums2, temp2 + 1, index - temp1 - 1);
        }
    }
    if (numNum > index) {
        if (nums1[temp1] > nums2[temp2]) {
            return find(nums1, temp1, nums2, nums2Size, index);
        } else {
            return find(nums1, nums1Size, nums2, temp2, index);
        }

    } else {
        if (nums1[temp1] > nums2[temp2]) {
            return find(nums1, nums1Size, nums2 + temp2 + 1, nums2Size - temp2 - 1, index - temp2 - 1);
        } else {
            return find(nums1 + temp1 + 1, nums1Size - temp1 - 1, nums2, nums2Size, index - temp1 - 1);
        }
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int index = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) % 2 != 0) {
        return (double)find(nums1, nums1Size, nums2, nums2Size, index);
    } else {
        double temp = (double)(find(nums1, nums1Size, nums2, nums2Size, index) + find(nums1, nums1Size, nums2, nums2Size, index - 1));
        return temp / 2;
    }
}
