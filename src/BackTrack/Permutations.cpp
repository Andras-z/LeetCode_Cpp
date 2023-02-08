// https://leetcode.com/problems/permutations/
#include "common.h"

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int start) {
        // 触发结束条件
        if (start == nums.size() - 1) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // swap
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1);
            // swap
            swap(nums[start], nums[i]);
        }
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {1, 2, 3};

    printNums(nums);

    vector<vector<int>> ans = res.permute(nums);

    cout << "Permutations. " << endl;

    for (int i = 0; i < ans.size(); i++) {
        printNums(ans[i]);
    }

    return 1;
}