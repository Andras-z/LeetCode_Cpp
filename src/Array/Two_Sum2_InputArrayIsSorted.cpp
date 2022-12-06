// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        // sort(numbers.begin(), numbers.end());
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }
        }
        return {};
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
    Solution res;
    vector<int> nums = {2,7,11,15};

    show(nums, 0);

    vector<int> ans = res.twoSum(nums, 9);

    cout << "Two Sum II - Input Array Is Sorted." << endl;

    show(ans, 0);

    return 1;
}