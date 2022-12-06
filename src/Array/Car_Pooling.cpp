// https://leetcode.com/problems/car-pooling/
#include <bits/stdc++.h>

using namespace std;

class Difference {
public:
    vector<int> diff; // diff[i]记录nums[i] - nums[i - 1]的差值

    Difference(vector<int>& nums) {
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1001);
        Difference df(nums);

        for (auto trip : trips) {
            int i = trip[1];
            // 第trip[2] 站乘客下车，即乘客在车上的区间是[trip[1], trip[2] - 1]
            int j = trip[2] - 1;
            int val = trip[0];
            df.increment(i, j, val);
        }

        vector<int> res = df.result();

        // 客车自始至终都不应该超载
        for (int i = 0; i < res.size(); i++) {
            if (capacity < res[i]) {
                return false;
            }
        }
        return true;
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
    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };

    showMatrix(trips);

    bool ans = res.carPooling(trips, 4);

    cout << "Car Pooling. " << ans << endl;

    return 1;
}