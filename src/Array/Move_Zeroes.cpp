// https://leetcode.com/problems/move-zeroes/submissions/
#include <bits/stdc++.h>

using namespace std;

int removeElements(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    for (; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = removeElements(nums, 0);
        for (int i = p; i < nums.size(); i++) {
            nums[i] = 0;
        }
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
    vector<int> nums = {0,1,0,3,12};

    show(nums, 0);

    res.moveZeroes(nums);

    cout << "Move Zeroes." << endl;

    show(nums, 0);

    return 1;
}