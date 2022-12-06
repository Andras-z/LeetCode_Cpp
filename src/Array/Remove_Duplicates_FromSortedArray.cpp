// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }

        return slow + 1;
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
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    show(nums, 0);

    int ans = res.removeDuplicates(nums);

    cout << "Remove Duplicates From Sorted Array." << endl;

    show(nums, ans);

    return 1;
}