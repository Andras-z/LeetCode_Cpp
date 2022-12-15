// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include "common.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = nullptr;
        root->right = left;

        TreeNode *p = root;
        while (p->right != nullptr) {
            p = p->right;
        }

        p->right = right;
    }
};

int main()
{
    TreeNode* root = stringToTreeNode("[1,2,5,3,4,null,6]");
    prettyPrintTree(root);

    Solution res;

    cout << "Flatten Binary Tree to Linked List." << endl;

    res.flatten(root);

    prettyPrintTree(root);

    return 0;
}