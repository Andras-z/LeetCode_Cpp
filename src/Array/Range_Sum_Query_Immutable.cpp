// https://leetcode.com/problems/range-sum-query-immutable/
#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> preSum; // preSum[i]记录nums[0..i-1]的累加和

    NumArray(vector<int>& nums) {
        preSum.push_back(0); // preSum[0] = 0, 便于计算累加和
        for (int i = 1; i <= nums.size(); i++) {
            preSum.push_back(preSum[i - 1] + nums[i - 1]);
        }
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

void show(vector<int>& nums, int size)
{
    if (size == 0) {
        size = nums.size();
    }
    cout << "nums:[";
    for (int i = 0; i < size; i++) {
        cout << nums[i];
        if (i != size - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main(void)
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *res = new NumArray(nums);

    show(nums, 0);

    cout << "Range Sum Query - Immutable." << endl;

    cout << "[0,2]: " << res->sumRange(0, 2) << endl;

    cout << "[2,5]: " << res->sumRange(2, 5) << endl;

    cout << "[0,5]: " << res->sumRange(0, 5) << endl;

    return 1;
}