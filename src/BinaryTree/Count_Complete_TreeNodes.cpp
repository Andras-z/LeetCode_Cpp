// https://leetcode.com/problems/count-complete-tree-nodes/
#include "common.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        int hl = 0, hr = 0;
        if (root == nullptr) {
            return 0;
        }

        TreeNode *left = root;
        while (left != nullptr) {
            hl++;
            left = left->left;
        }

        TreeNode *right = root;
        while (right != nullptr) {
            hr++;
            right = right->right;
        }

        if (hl == hr) {
            return pow(2, hl) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    TreeNode* root = stringToTreeNode("[1,2,3,4,5,6,7,8,9]");
    prettyPrintTree(root);

    Solution res;

    cout << "Count Complete Tree Nodes." << endl;

    cout << res.countNodes(root) << endl;

    return 0;
}