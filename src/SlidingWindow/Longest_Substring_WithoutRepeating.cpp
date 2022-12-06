// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int len = 0;

        while (right < s.length()) {
            char c = s[right];
            right++;
            window[c]++;

            while (window[c] > 1) {
                len = max(len, right - left - 1);
                char d = s[left];
                left++;
                window[d]--;
            }
        }

        // 考虑s不包含重复字符的情况，最大值为right - left
        return max(len, right - left);
    }
};

int main(void)
{
    Solution res;
    string str = "eabcdefga";

    cout << str << endl;

    int ans = res.lengthOfLongestSubstring(str);

    cout << "Longest Substring Without Repeating Characters." << endl;

    cout << ans << endl;

    return 1;
}