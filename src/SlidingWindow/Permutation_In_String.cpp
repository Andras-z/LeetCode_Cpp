// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        for (char c : s1) {
            need[c]++;
        }

        while (right < s2.size()) {
            char c = s2[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return false;
    }
};

int main(void)
{
    Solution res;
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << s1 << endl;
    cout << s2 << endl;

    bool ans = res.checkInclusion(s1, s2);

    cout << "Permutation In String." << endl;

    cout << "true/false " << ans << endl;

    return 1;
}