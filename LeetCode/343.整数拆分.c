/*
 * @lc app=leetcode.cn id=343 lang=c
 *
 * [343] 整数拆分
 */

// @lc code=start
#define maxn 60
#define clr(a, b) memset(a, b, sizeof(a))

int getmax(int a, int b) {
    return a > b ? a : b;
}

int dp[maxn];

int integerBreak(int n){
    clr(dp, 0);
    if (n <= 2) return 1;
    if (n == 3) return 2;
    for (int i=1; i<=n; ++i) {
        dp[i] = getmax(dp[i], i);
        for (int k=1; k<i; ++k) {
            dp[i] = getmax(dp[i], dp[i-k] * k);
        }
    }
    return dp[n];
}


// @lc code=end