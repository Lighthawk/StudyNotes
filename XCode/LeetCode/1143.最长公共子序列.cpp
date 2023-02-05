/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string t1, string t2) {
        int l1 = t1.size();
        int l2 = t2.size();
        memset(dp, 0, sizeof(dp));
        if (t1[0] == t2[0]) dp[0][0] = 1;
        for (int i=1; i<l1; ++i) dp[i][0] = (t1[i] == t2[0]) ? 1 : dp[i-1][0];
        for (int j=1; j<l2; ++j) dp[0][j] = (t1[0] == t2[j]) ? 1 : dp[0][j-1];
        for (int i=1; i<l1; ++i) {
            for (int j=1; j<l2; ++j) {
                if (t1[i] == t2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[l1-1][l2-1];
    }
};
// @lc code=end

