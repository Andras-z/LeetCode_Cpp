// https://leetcode.com/problems/minimum-window-substring/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;

        for (char c : t) {
            need[c]++;
        }

        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main(void)
{
    Solution res;
    string str = "ADOBECODEBANC";
    string t = "ABC";

    cout << str << endl;
    cout << t << endl;

    string ans = res.minWindow(str, t);

    cout << "Minimum Window Substring." << endl;

    cout << ans << endl;

    return 1;
}