// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>

using namespace std;

static int palindrome(string s, int l, int r)
{
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }

    return r - l - 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int strat = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = palindrome(s, i, i);
            int len2 = palindrome(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                strat = i - (len - 1) / 2;
            }
        }

        return s.substr(strat, maxLen);
    }
};

int main(void)
{
    Solution res;
    string str = "babad";

    cout << str << endl;

    string ans = res.longestPalindrome(str);

    cout << "Longest Palindromic Substring." << endl;

    cout << ans << endl;

    return 1;
}