/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */

// @lc code=start
class Solution {
public:
    static int cmp(int a, int b) {
        return a > b;
    }
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), cmp);
        int ret = 0;
        int len = piles.size();
        for (int i=1, cnt=0; i <len && cnt < len/3; i+=2, cnt ++) {
            ret += piles[i];
        }
        return ret;
    }
};
// @lc code=end

