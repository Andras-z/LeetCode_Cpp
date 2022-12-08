// https://leetcode.com/problems/advantage-shuffle/
#include "common.h"

struct VecCmp {
    bool operator() (vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<vector<int>, vector<vector<int>>, VecCmp> maxpq;
        // 给nums2降序排序
        for (int i = 0; i < nums2.size(); i++) {
            maxpq.push({i, nums2[i]});
        }
        // 给nums1升序排序
        sort(nums1.begin(), nums1.end());

        // nums1[left]是最小值，nums1[right]是最大值
        int left = 0, right = nums1.size() - 1;
        vector<int> res(nums1.size());
        while (!maxpq.empty()) {
            vector<int> pair = maxpq.top();
            maxpq.pop();
            // maxval是nums2中的最大值，i是对应索引值
            int i = pair[0], maxval = pair[1];
            if (maxval < nums1[right]) {
                // 如果nums[right]能胜过maxval，那就自己上
                res[i] = nums1[right];
                right--;
            } else {
                // 否则用最小值混一下，养精蓄锐
                res[i] = nums1[left];
                left++;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution res;
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {1, 10, 4, 11};

    printNums(nums1);
    printNums(nums2);

    vector<int> ans = res.advantageCount(nums1, nums2);

    cout << "Advantage Shuffle. " << endl;

    printNums(ans);
    printNums(nums2);

    return 1;
}