#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* stringToListNode(string input);

void prettyPrintLinkedList(ListNode* node);

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* stringToTreeNode(string input);

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true);

void printNums(vector<int>& nums, int size = 0);

void printMatrix(vector<vector<int>>& matrix);
