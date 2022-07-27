// https://leetcode.com/problems/longest-palindromic-substring/submissions/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        // rows represent start of my substring
        // columns represent end of my substring

        /*
        abc

        a, substring starts and ends at 'a'
        ab, substring starts at 'a', and ends at 'b'
        abc

        b
        bc

        c

        for palindrome we only care for endpoints,
        as middle part of the subtstring is just another subproblem itself
        */

        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int mx = 0, index = -1;

        // iterating over the possible gap b/w the endpoints
        for (int gap = 0; gap < n; gap++) {

            int start = 0, end = gap;
            while (end < n) {

                if (gap == 0) {
                    dp[start][end] = 1;
                } else if (gap == 1) {
                    dp[start][end] = s[start] == s[end] ? 2 : 0;
                } else {
                    int prev = dp[start + 1][end - 1];
                    int ans = (s[start] == s[end]) ? 2 : 0;
                    dp[start][end] = (prev > 0) ? (ans > 0 ? ans + prev : 0) : 0;
                }

                if (dp[start][end] > mx) {
                    mx = dp[start][end];
                    index = end;
                }

                end++;
                start++;
            }
        }



        for (int i = index; i > index - mx; i--) {
            ans += s[i];
        }



        return ans;
    }
};