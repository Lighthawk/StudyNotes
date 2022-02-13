/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

const int maxm = 201;
const int maxv = 0x3f3f3f3f;

class Solution {
public:
    int dp[maxm][maxm];
    int minFallingPathSum(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        int ret = maxv;
        memset(dp, maxv, sizeof(dp));

        for (int j=0; j<col; ++j) {
            dp[0][j] = arr[0][j];
        }
        for (int i=1; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                for (int k=0; k<col; ++k) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
        for (int j=0; j<col; ++j) {
            ret = min(ret, dp[row-1][j]);
        }
        return ret;
    }
};
// @lc code=end

