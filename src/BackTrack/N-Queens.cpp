// https://leetcode.com/problems/n-queens/
#include "common.h"

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string> &board, int row) {
        // 触发结束条件
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board[row].size(); col++) {
            if (!isValid(board, row, col)) {
                continue;
            }
            // 做选择
            board[row][col] = 'Q';
            // 进入下一次决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string> &board, int row, int col) {
        // 检查列
        for (int i = 0; i <= row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查右上角
        for (int i = row - 1, j = col + 1; i >= 0 && j <= board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查左上角
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    Solution res;

    vector<vector<string>> ans = res.solveNQueens(4);

    cout << "N-Queens. " << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << "ans " << i + 1 << endl;
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 1;
}