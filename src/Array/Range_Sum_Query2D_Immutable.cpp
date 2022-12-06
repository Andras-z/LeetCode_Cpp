// https://leetcode.com/problems/range-sum-query-2d-immutable/
#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>>& matrix) {
        preSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1,0));
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                preSum[i][j] = (preSum[i][j - 1] + preSum[i - 1][j] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

void show(vector<int>& nums, int size)
{
    if (size == 0) {
        size = nums.size();
    }
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << nums[i];
        if (i != size - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void showMatrix(vector<vector<int>>& matrix)
{
    cout << "matrix:" << endl;
    for (auto nums : matrix) {
        show(nums, 0);
    }
}

int main(void)
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix *res = new NumMatrix(matrix);

    showMatrix(matrix);

    cout << "Range Sum Query 2D - Immutable." << endl;

    cout << "[(2,1), (4,3)]: " << res->sumRegion(2, 1, 4, 3) << endl;

    cout << "[(1,1), (2,2)]: " << res->sumRegion(1, 1, 2, 2) << endl;

    cout << "[(1,2), (2,4)]: " << res->sumRegion(1, 2, 2, 4) << endl;

    return 1;
}