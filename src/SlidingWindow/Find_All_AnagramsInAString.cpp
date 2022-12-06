// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        for (char c : p) {
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

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
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

        return res;
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
    string s = "abab";
    string p = "ab";

    cout << s << endl;
    cout << p << endl;

    vector<int> ans = res.findAnagrams(s, p);

    cout << "Find All Anagrams in a String." << endl;

    show(ans, 0);

    return 1;
}