// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i]);
        }
    }

    void reverse(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
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

    cout << "Rotate Image. " << endl;

    res.rotate(matrix);

    showMatrix(matrix);

    return 1;
}