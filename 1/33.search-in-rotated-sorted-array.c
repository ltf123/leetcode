/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 */
/*

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int start = 0, end = nums.size(); start < end;){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] > nums[start]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid;
                }else{
                    start = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[end - 1]){
                    start = mid + 1;
                }else{
                    end = mid;
                }
            }
        }
        
        return -1;
    }
};


自己写的代码太复杂，有些地方应该用<=或>=的忘记用了倒在了[1,3]3,和[3,1]1上，复杂自己一眼也不想多看
，上面那个C++简单多了，
*/
#include <stdbool.h>
bool isInLargePart(int* nums, int low, int high, int temp)
{
    if (nums[high] > nums[low]) {
        return false;
    }
    if (nums[low] <= nums[temp]) {
        return true;
    } else {
        return false;
    }
}
int find(int* nums, int low, int high, int target)
{
    if (low > high) {
        return -1;
    }
    int temp = (low + high) / 2;
    if (nums[temp] == target) {
        return temp;
    } else if (nums[temp] > target) {
        if (isInLargePart(nums, low, high, temp)) {
            if (nums[low] > target) {
                return find(nums, temp + 1, high, target);
            } else {
                return find(nums, low, temp - 1, target);
            }

        } else {
            return find(nums, low, temp - 1, target);
        }

    } else {
        if (isInLargePart(nums, low, high, temp)) {
            return find(nums, temp + 1, high, target);
        } else {
            if (nums[high] >= target) {
                return find(nums, temp + 1, high, target);
            } else {
                return find(nums, low, temp - 1, target);
            }
        }
    }
}

int search(int* nums, int numsSize, int target)
{
    return find(nums, 0, numsSize - 1, target);
}
