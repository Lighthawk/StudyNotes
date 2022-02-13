/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
#define maxn 16
#define LL long long
class Solution {
public:
    const LL mod  = 1000000007L;
    const LL maxv = 0x3f3f3f3f3f3f;
    LL getmax(LL a, LL b) {
        return (a > b ? a : b);
    }
    LL getmin(LL a, LL b) {
        return (a < b ? a : b);
    }
    LL getmod(LL x) {
        if (x >= 0) return x % mod;
        return -((-x) % mod);
    }
    int maxProductPath(vector<vector<int>>& grid) {
        LL dpmax[maxn][maxn];
        LL dpmin[maxn][maxn];
        int r = grid.size();
        int c = grid[0].size();
        dpmax[0][0] = (LL)grid[0][0];
        dpmin[0][0] = (LL)grid[0][0];
        for (int i=1; i<r; ++i) {
            dpmax[i][0] = dpmin[i][0] = dpmax[i-1][0] * (LL)grid[i][0];
        }
        for (int j=1; j<c; ++j) {
            dpmax[0][j] = dpmin[0][j] = dpmax[0][j-1] * (LL)grid[0][j];
        }
        for (int i=1; i<r; ++i) {
            for (int j=1; j<c; ++j) {
                LL v1, v2;
                v1 = getmax(dpmax[i-1][j], dpmax[i][j-1]) * (LL)grid[i][j];
                v2 = getmin(dpmin[i-1][j], dpmin[i][j-1]) * (LL)grid[i][j];  

                dpmax[i][j] = getmax(v1, v2);
                dpmin[i][j] = getmin(v1, v2);
            }
        }
        return dpmax[r-1][c-1] >= 0 ? getmod(dpmax[r-1][c-1]) : -1;
    }
};
// @lc code=end

