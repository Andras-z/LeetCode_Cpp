// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include "common.h"

class Solution {
public:
    vector<int> count;
    vector<pair<int, int>> temp;

    vector<int> countSmaller(vector<int>& nums) {
        count = vector<int>(nums.size());
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(make_pair(i, nums[i]));
            temp.push_back(make_pair(i, nums[i]));
        }

        mergeSort(arr, 0, arr.size() - 1);
        return count;
    }

    void mergeSort(vector<pair<int, int>> &arr, int lo, int hi) {
        if (lo == hi) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);

        merge(arr, lo, mid, hi);
    }

    void merge(vector<pair<int, int>> &arr, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = arr[i];
        }

        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (j == hi + 1) {
                arr[p] = temp[i++];
                count[arr[p].first] += j - mid - 1;
            } else if (i == mid + 1) {
                arr[p] = temp[j++];
            } else if (temp[i].second > temp[j].second) {
                arr[p] = temp[j++];
            } else {
                arr[p] = temp[i++];
                count[arr[p].first] += j - mid - 1;
            }
        }
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {5,2,6,1};

    printNums(nums);

    vector<int> ans = res.countSmaller(nums);

    cout << "Count of Smaller Numbers After Self. " << endl;

    printNums(ans);

    return 1;
}