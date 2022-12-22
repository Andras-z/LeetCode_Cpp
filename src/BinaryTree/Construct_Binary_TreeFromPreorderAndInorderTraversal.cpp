// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include "common.h"

class Solution {
public:
    unordered_map<int, int> valToIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        int index = valToIndex[preorder[preStart]];
        int leftSize = index - inStart;

        TreeNode *left = build(preorder, preStart + 1, preStart + leftSize,
                                inorder, inStart, index - 1);
        TreeNode *right = build(preorder, preStart + leftSize + 1, preEnd,
                                inorder, index + 1, inEnd);

        root->left = left;
        root->right = right;

        return root;
    }
};

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution res;

    cout << "Construct Binary Tree from Preorder and Inorder Traversal." << endl;

    cout << "preorder:";
    printNums(preorder);

    cout << "inorder:";
    printNums(inorder);

    TreeNode* ans = res.buildTree(preorder, inorder);

    prettyPrintTree(ans);

    return 0;
}