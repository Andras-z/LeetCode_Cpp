// https://leetcode.com/problems/diameter-of-binary-tree/description/
#include "common.h"

class Solution {
public:
    int diameter;

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        maxDepth(root);
        return diameter; 
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        diameter = max(diameter, left + right);

        return max(left, right) + 1; 
    }
};

int main() {

    TreeNode* root = stringToTreeNode("[1,2,3,4,5]");
    prettyPrintTree(root);

    Solution res;

    cout << "Diameter of Binary Tree." << endl;

    int ans = res.diameterOfBinaryTree(root);

    cout << ans << endl;

    return 0;
}