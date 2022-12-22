// https://leetcode.com/problems/sort-an-array/description/
#include "common.h"

class Solution {
public:
    vector<int> temp;

    vector<int> sortArray(vector<int>& nums) {
        temp = vector<int>(nums.size());
        // mergeSort(nums, 0, nums.size() - 1);
        // 为了避免出现耗时的极端情况，先随机打乱
        shuffle(nums);
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        // 对nums[lo..hi]进行切分，使得nums[lo..p-1] <= nums[p] < nums[p+1..hi]
        int p = partition(nums, lo, hi);

        quickSort(nums, lo, p - 1);
        quickSort(nums, p + 1, hi);
    }

    // 对nums[lo..hi]进行切分
    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[lo];

        // 关于区间的边界控制需格外小心，这里把i,j定义为开区间，同时定义：
        // [lo, i) <= pivot; (j, hi] > pivot
        // 之后都要正确维护这个边界区间的定义
        int i = lo + 1, j = hi;
        while (i <= j) {
            while (i < hi && nums[i] <= pivot) {
                i++;
            }

            while (j > lo && nums[j] > pivot) {
                j--;
            }
            // 此时[lo, i) <= pivot && (j, hi] > pivot

            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }

        // 将pivot放到合适的位置，即pivot左边元素较小，右边元素较大
        swap(nums[lo], nums[j]);
        return j;
    }

    void shuffle(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int r = i + (rand() % (n - i));
            swap(nums[i], nums[r]);
        }
    }

    void mergeSort(vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);

        merge(nums, lo, mid, hi);
    }

    void merge(vector<int> &nums, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = nums[i];
        }

        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (j == hi + 1) {
                nums[p] = temp[i++];
            } else if (i == mid + 1) {
                nums[p] = temp[j++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
            }
        }
    }
};

int main(void)
{
    Solution res;
    vector<int> nums = {5,1,1,2,0,0};

    printNums(nums);

    vector<int> ans = res.sortArray(nums);

    cout << "Sort an Array. " << endl;

    printNums(ans);

    return 1;
}