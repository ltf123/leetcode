/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */
//草 这道题写了这么久，分支情况太多，写的提交了5次，才把分支全部搞对，擦，

//下面官方解法，看了好久才明白，真是笨啊s
// double find(int* nums1, int nums1Size, int* nums2, int nums2Size)
// {
//     int halfLen = (nums1Size + nums2Size + 1) / 2;
//     int iMin = 0;
//     int iMax = nums1Size;
//     while (iMin <= iMax) {
//         int i = (iMax + iMin) / 2;
//         int j = halfLen - i;
//         if (i < iMax && nums1[i] < nums2[j - 1]) {
//             iMin = i + 1;
//         } else if (i > iMin && nums1[i - 1] > nums2[j]) {
//             iMax = i - 1;
//         } else {
//             int maxLeft = 0;
//             if (i == 0) {
//                 maxLeft = nums2[j - 1];
//             } else if (j == 0) {
//                 maxLeft = nums1[i - 1];
//             } else {
//                 maxLeft = nums2[j - 1] > nums1[i - 1] ? nums2[j - 1] : nums1[i - 1];
//             }
//             if ((nums1Size + nums2Size) % 2 == 1) {
//                 return maxLeft;
//             }

//             int maxRight = 0;

//             if (i == nums1Size) {
//                 maxRight = nums2[j];
//             } else if (j == nums2Size) {
//                 maxRight = nums1[i];
//             } else {
//                 maxRight = nums2[j] > nums1[i] ? nums1[i] : nums2[j];
//             }
//             return (maxLeft + maxRight) / 2.0;
//         }
//     }
//     return 0.0;
// }
// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
// {
//     if (nums1Size > nums2Size) {
//         return find(nums2, nums2Size, nums1, nums1Size);
//     } else {
//         return find(nums1, nums1Size, nums2, nums2Size);
//     }
// }
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
