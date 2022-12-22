// https://leetcode.com/problems/maximum-binary-tree/
#include "common.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }

        int index;
        // find index
        int maxVal = INT_MIN;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                index = i;
            }
        }

        TreeNode *node = new TreeNode(nums[index]);

        TreeNode *left = build(nums, lo, index - 1);
        TreeNode *right = build(nums, index + 1, hi);

        node->left = left;
        node->right = right;

        return node;
    }
};

int main()
{
    vector<int> nums = {3,2,1,6,0,5};
    Solution res;

    cout << "Maximum Binary Tree." << endl;

    TreeNode* ans = res.constructMaximumBinaryTree(nums);

    prettyPrintTree(ans);

    return 0;
}