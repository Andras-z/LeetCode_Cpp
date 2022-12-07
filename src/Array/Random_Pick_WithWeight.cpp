// https://leetcode.com/problems/random-pick-with-weight/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> preSum;

    Solution(vector<int>& w) {
        preSum.push_back(0);
        for (int i = 1; i <= w.size(); i++) {
            preSum.push_back(preSum[i - 1] + w[i - 1]);
        }
    }

    int pickIndex() {
        int left = 0;
        int right = preSum.size() - 1;
        int target = rand() % preSum[preSum.size() - 1] + 1;
        int mid = 0;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (preSum[mid] == target) {
                right = mid - 1; // 缩小查找空间
            } else if (preSum[mid] < target) {
                left = mid + 1;
            } else if (preSum[mid] > target) {
                right = mid - 1;
            }
        }

        return left - 1;
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
    vector<int> nums = {4, 2};
    Solution *res = new Solution(nums);

    show(nums, 0);

    cout << "Random Pick with Weight." << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    cout << "pickIndex " << res->pickIndex() << endl;

    return 1;
}