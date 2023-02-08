// https://leetcode.com/problems/delete-node-in-a-bst/
#include "common.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }

            // 获取右子树的最小的节点
            TreeNode *minNode = getMin(root->right);
            // 删除右子树最小的节点
            root->right = deleteNode(root->right, minNode->val);

            // 用右子树最小的节点替换root节点
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    TreeNode *getMin(TreeNode *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};

int main()
{
    TreeNode* root = stringToTreeNode("[5,3,6,2,4,null,7]");
    prettyPrintTree(root);

    Solution res;

    cout << "Delete Node in a BST." << endl;

    TreeNode *ans = res.deleteNode(root, 3);

    prettyPrintTree(ans);

    return 0;
}