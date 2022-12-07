#include "common.h"

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        prettyPrintTree(root);
    }
    return 0;
}