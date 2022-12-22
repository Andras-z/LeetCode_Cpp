// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include "common.h"

class Solution {
public:
    unordered_map<int, int> valToIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int> &inorder, int inStart, int inEnd,
                    vector<int> &postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int index = valToIndex[postorder[postEnd]];
        int leftSize = index - inStart;

        TreeNode *left = build(inorder, inStart, index - 1,
                                postorder, postStart, postStart + leftSize - 1);
        TreeNode *right = build(inorder, index + 1, inEnd,
                                postorder, postStart + leftSize, postEnd - 1);

        root->left = left;
        root->right = right;

        return root;
    }
};

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution res;

    cout << "Construct Binary Tree from Inorder and Postorder Traversal." << endl;

    cout << "inorder:";
    printNums(inorder);

    cout << "postorder:";
    printNums(postorder);

    TreeNode* ans = res.buildTree(inorder, postorder);

    prettyPrintTree(ans);

    return 0;
}