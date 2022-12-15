// https://leetcode.com/problems/invert-binary-tree/description/
#include "common.h"

class Solution {
public:
    // [分解问题]解法
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

    // [遍历]解法
    TreeNode* invertTree_traverse(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main()
{
    TreeNode* root = stringToTreeNode("[4,2,7,1,3,6,9]");
    prettyPrintTree(root);

    Solution res;

    cout << "Invert Binary Tree." << endl;

    TreeNode* ans = res.invertTree(root);

    prettyPrintTree(ans);

    return 0;
}