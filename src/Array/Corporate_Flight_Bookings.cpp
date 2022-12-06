// https://leetcode.com/problems/corporate-flight-bookings/description/
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        Difference df(nums);

        for (auto booking : bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            df.increment(i, j, val);
        }

        return df.result();
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
    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };

    showMatrix(bookings);

    cout << "Corporate Flight Bookings." << endl;

    vector<int> ans = res.corpFlightBookings(bookings, 5);

    show(ans, 0);

    return 1;
}