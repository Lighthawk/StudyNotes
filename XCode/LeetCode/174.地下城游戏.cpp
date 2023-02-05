/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#define maxv 0x3f3f3f3f

class Solution {
public:
    int getmax(int a, int b) {
        return a > b ? a : b;
    }

    int check(int v, vector<vector<int>>&mp) {
        if (v + mp[0][0] <= 0) return 0;

        int row = mp.size();
        int col = mp[0].size();
        vector<vector<int>> dp;

        for (int i=0; i<row; ++i) {
            vector<int> a;
            for (int j=0; j<col; ++j) {
                a.push_back(-1);
            }
            dp.push_back(a);
        }

        dp[0][0] = v + mp[0][0];
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (i ==0 && j == 0) continue;
                if (j > 0 && dp[i][j - 1] != -1 && dp[i][j-1] + mp[i][j] > 0) {
                    dp[i][j] = getmax(dp[i][j], dp[i][j-1] + mp[i][j]);
                }
                if (i > 0 && dp[i-1][j] != -1 && dp[i-1][j] + mp[i][j] > 0) {
                    dp[i][j] = getmax(dp[i][j], dp[i-1][j] + mp[i][j]);
                }
            }
        }
        return dp[row - 1][col - 1] > 0 ? 1 : 0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 0, r = maxv, mid, ret;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid, dungeon)) {
                r = mid - 1;
                ret = mid;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }
};
// @lc code=end


