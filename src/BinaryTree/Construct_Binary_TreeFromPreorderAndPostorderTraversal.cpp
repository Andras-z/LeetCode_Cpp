// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#include "common.h"

class Solution {
public:
    unordered_map<int, int> valToIndex;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            valToIndex[postorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &postorder, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);

        if (preStart == preEnd) {
            return root;
        }

        int leftRootVal = preorder[preStart + 1];
        int index = valToIndex[leftRootVal];
        int leftSize = index - postStart + 1;

        TreeNode *left = build(preorder, preStart + 1, preStart + leftSize,
                                postorder, postStart, index);
        TreeNode *right = build(preorder, preStart + leftSize + 1, preEnd,
                                postorder, index + 1, postEnd - 1);

        root->left = left;
        root->right = right;

        return root;
    }
};

int main()
{
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    Solution res;

    cout << "Construct Binary Tree from Preorder and Postorder Traversal." << endl;

    cout << "preorder:";
    printNums(preorder);

    cout << "postorder:";
    printNums(postorder);

    TreeNode* ans = res.constructFromPrePost(preorder, postorder);

    prettyPrintTree(ans);

    return 0;
}