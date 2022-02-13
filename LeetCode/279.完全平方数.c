/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 */

// @lc code=start
#define maxv 0x3f3f3f3f
#define maxn 1000007
#define maxm 1001
#define clr(a, b) memset(a, b, sizeof(a))

inline int getmin(const int a, const int b) {
    return a < b ? a : b;
}

int dp[maxn];

int init(int n) {
    for (int i=0; i<=n; ++i) {
        dp[i] = maxv;
    }
    return (int)sqrt(n) + 1;
}

int numSquares(int n){
    int k = init(n);
    dp[n] = 0;
    for (int i=1; i<=k; ++i) {
        int v = i * i;
        for (int j=n; j>=v; --j) {
            dp[j - v] = getmin(dp[j - v], dp[j] + 1);
        }
    }
    return dp[0];
}
// @lc code=end

