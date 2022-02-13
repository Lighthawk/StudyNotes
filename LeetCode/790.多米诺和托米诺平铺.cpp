/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution {
public:
    const long long mod = 1e9 + 7;
    long long dp[1001];
    int numTilings(int N) {
        memset(dp, 0, sizeof(dp));
        dp[1] = 1L;
        dp[2] = 2L;
        dp[3] = 5L;
        for (int i=4; i<=N; ++i) {
            dp[i] = (dp[i-1] * 2L + dp[i-3]) % mod;
        }
        return (int)dp[N];
    }
};
// @lc code=end

