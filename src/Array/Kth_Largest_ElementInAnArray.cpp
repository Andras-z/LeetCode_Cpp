// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include "common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 为了避免出现耗时的极端情况，先随机打乱
        shuffle(nums);
        int lo = 0, hi = nums.size() - 1;

        k = nums.size() - k; // 转化成 排名第k的元素
        while (lo <= hi) {
            // 在nums[lo..hi]中选一个分界点
            int p = partition(nums, lo, hi);
            if (p < k) {
                // 第k个元素在nums[p+1..hi]中
                lo = p + 1;
            } else if (p > k) {
                // 第k个元素在nums[lo..p-1]中
                hi = p - 1;
            } else {
                // 找到第k大元素
                return nums[p];
            }
        }

        return -1;
    }

    // 对nums[lo..hi]进行切分
    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[lo];

        // 关于区间的边界控制需格外小心，这里把i,j定义为开区间，同时定义：
        // [lo, i) <= pivot; (j, hi] > pivot
        // 之后都要正确维护这个边界区间的定义
        int i = lo + 1, j = hi;
        while (i <= j) {
            while (i < hi && nums[i] <= pivot) {
                i++;
            }

            while (j > lo && nums[j] > pivot) {
                j--;
            }
            // 此时[lo, i) <= pivot && (j, hi] > pivot

            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }

        // 将pivot放到合适的位置，即pivot左边元素较小，右边元素较大
        swap(nums[lo], nums[j]);
        return j;
    }

    void shuffle(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int r = i + (rand() % (n - i));
            swap(nums[i], nums[r]);
        }
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};

    printNums(nums);

    int ans = res.findKthLargest(nums, 4);

    cout << "4th Largest Element in an Array. " << endl;

    cout << ans << endl;

    return 1;
}