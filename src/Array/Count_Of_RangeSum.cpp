// https://leetcode.com/problems/count-of-range-sum/
#include "common.h"

class Solution {
public:
    vector<long> preSum;
    vector<long> temp;
    int count;
    int myLower;
    int myUpper;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        temp = vector<long>(nums.size() + 1);
        preSum = vector<long>(nums.size() + 1);
        count = 0;
        myLower = lower;
        myUpper = upper;
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + (long)nums[i];
        }

        mergeSort(preSum, 0, preSum.size() - 1);
        return count;
    }

    void mergeSort(vector<long> &nums, int lo, int hi) {
        if (lo == hi) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);

        merge(nums, lo, mid, hi);
    }

    void merge(vector<long> &nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = nums[i];
        }

        // 进行效率优化，维护左闭右开区间[start, end)中的元素和nums[i]的差在[lower, upper]中
        int start = mid + 1, end = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (start <= hi && nums[start] - nums[i] < myLower) {
                start++;
            }
            while (end <= hi && nums[end] - nums[i] <= myUpper) {
                end++;
            }
            count += end - start;
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
    vector<int> nums = {-2,5,-1};

    printNums(nums);

    int ans = res.countRangeSum(nums, -2, 2);

    cout << "Count of Range Sum. lower=-2, upper=2" << endl;

    cout << ans << endl;

    return 1;
}