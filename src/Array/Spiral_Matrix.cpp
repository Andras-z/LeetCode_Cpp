// https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left_bound = 0;
        int right_bound = matrix[0].size() - 1;
        int upper_bound = 0;
        int lower_bound = matrix.size() - 1;
        vector<int> res;
        int size = matrix.size() * matrix[0].size();

        while (res.size() < size) {
            // 在顶部从左往右遍历
            if (upper_bound <= lower_bound) {
                for (int j = left_bound; j <= right_bound; j++) {
                    res.push_back(matrix[upper_bound][j]);
                }
                upper_bound++;
            }

            // 在右侧从上往下遍历
            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) {
                    res.push_back(matrix[i][right_bound]);
                }
                right_bound--;
            }

            // 在底部从右往左遍历
            if (upper_bound <= lower_bound) {
                for (int j = right_bound; j >= left_bound; j--) {
                    res.push_back(matrix[lower_bound][j]);
                }
                lower_bound--;
            }

            // 在左侧从下往上遍历
            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    res.push_back(matrix[i][left_bound]);
                }
                left_bound++;
            }
        }

        return res;
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
    Solution res;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    showMatrix(matrix);

    cout << "Spiral Matrix. " << endl;

    vector<int> ans = res.spiralOrder(matrix);

    show(ans, 0);

    return 1;
}