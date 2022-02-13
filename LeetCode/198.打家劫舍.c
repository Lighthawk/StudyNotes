/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start

int getmax(int a, int b) {
    return a > b ? a : b;
}

int rob(int* s, int len){
    int *dp = (int *)malloc(sizeof(int) * len);
    memset(dp, 0, sizeof(int) * len);

    int premax = -1, pre2max = -1;
    if (len == 0) return 0;
    if (len == 1) return s[0];
    if (len == 2) return getmax(s[0], s[1]);
    dp[0] = pre2max = s[0];
    dp[1] = premax  = s[1];
    for (int i=2; i<len; ++i) {
        dp[i] = getmax(dp[i], pre2max + s[i]);
        pre2max = getmax(premax, pre2max);
        premax = getmax(premax, dp[i]);
    }
    return getmax(dp[len-1], dp[len-2]);
}
// @lc code=end

