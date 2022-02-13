/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
    int spc(int x) {
        if (x % 4 == 0) return -2;
        if (x % 4 == 1) return 0;
        return 1;
    }
    int clumsy(int N) {
        if (N <= 2) return N;
        if (N == 3) return 6;
        if (N == 4) return 7;

        return N * (N-1) / (N-2) + spc(N - 3);
    }
};
// @lc code=end

