// https://leetcode.com/problems/binary-search/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }
};

void show(vector<int>& nums, int size)
{
    if (size == 0) {
        size = nums.size();
    }
    cout << "nums:[";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << ",";
    }
    cout << "]" << endl;
}

int main(void)
{
    Solution res;
    vector<int> nums = {-1,0,3,5,9,12};

    show(nums, 0);

    int ans = res.search(nums, 9);

    cout << "Binary Search." << endl;

    cout << ans << endl;

    return 1;
}