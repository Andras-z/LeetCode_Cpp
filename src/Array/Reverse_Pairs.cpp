// https://leetcode.com/problems/reverse-pairs/
#include "common.h"

class Solution {
public:
    vector<int> temp;
    int count;

    int reversePairs(vector<int>& nums) {
        temp = vector<int>(nums.size());
        count = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }

    void mergeSort(vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);

        merge(nums, lo, mid, hi);
    }

    void merge(vector<int> &nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = nums[i];
        }

        // 进行效率优化，维护左闭右开区间[mid + 1, end)中的元素乘2小于nums[i]
        int end = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (end <= hi && (long)nums[i] > (long)nums[end] * 2) {
                end++;
            }
            count += end - (mid + 1);
        }

        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (j == hi + 1) {
                nums[p] = temp[i++];
            } else if (i == mid + 1) {
                nums[p] = temp[j++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
            }
        }
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {1,3,2,3,1};

    printNums(nums);

    int ans = res.reversePairs(nums);

    cout << "Reverse Pairs. " << ans << endl;

    return 1;
}