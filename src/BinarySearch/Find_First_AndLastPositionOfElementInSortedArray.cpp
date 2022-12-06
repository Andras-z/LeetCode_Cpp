// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int search(vector<int>& nums, int target) {
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

static int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1; // 缩小查找空间
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (left == nums.size()) {
        return -1;
    }

    return nums[left] == target ? left : -1;
}

static int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 缩小查找空间
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (left - 1 < 0) {
        return -1;
    }

    return nums[left - 1] == target ? left - 1 : -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target), right_bound(nums, target)};
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
    vector<int> nums = {5,7,7,8,8,10};

    show(nums, 0);

    vector<int> ans = res.searchRange(nums, 7);

    cout << "Binary Search." << endl;

    show(ans, 0);

    return 1;
}