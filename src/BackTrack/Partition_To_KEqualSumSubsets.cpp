// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
#include "common.h"

class Solution {
public:
    unordered_map<int, bool> memo;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return false;
        }
        int sum = 0;
        for (int v : nums) {
            sum += v;
        }

        if ((sum % k) != 0) {
            return false;
        }

        int target = sum / k;

        return backTrack(k, 0, nums, 0, 0, target);
    }

    bool backTrack(int k, int bucket, vector<int>&nums, int start, int used, int target) {
        // base case
        if (k == 0) {
            return true;
        }

        // 装满了当前桶，递归穷举下一个桶的选择
        if (bucket == target) {
            // 让下一个桶从nums[0]开始选数字
            bool res = backTrack(k - 1, 0, nums, 0, used, target);
            memo[used] = res;
            return res;
        }

        // 剪枝，避免冗余计算
        if (memo.count(used)) {
            return memo[used];
        }

        for (int i = start; i < nums.size(); i++) {
            if (((used >> i) & 1) == 1) { // 判断第i位是否为1
                // nums[i]已被装入别的桶中
                continue;
            }

            if (nums[i] + bucket > target) {
                continue;
            }

            // 做选择
            used |= 1 << i; // 将第i位置为1
            bucket += nums[i];

            // 穷举递归下一个数字是否装入当前桶
            if (backTrack(k, bucket, nums, i + 1, used, target)) {
                return true;
            }

            // 撤销选择
            used ^= 1 << i; // 使用异或将第i位恢复0
            bucket -= nums[i];
        }

        return false;
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};

    bool ans = res.canPartitionKSubsets(nums, 4);

    cout << "Partition_To_KEqualSumSubsets. " << ans << endl;

    return 1;
}