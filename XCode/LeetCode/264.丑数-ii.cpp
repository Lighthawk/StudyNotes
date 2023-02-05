/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    const long long maxv = 2130000007;
    int factor[3] = {2, 3, 5};
    long long pow2[32];
    long long pow3[21];
    long long pow5[14];

    void init() {
        memset(pow2, 0, sizeof(pow2));
        memset(pow3, 0, sizeof(pow3));
        memset(pow5, 0, sizeof(pow5));
        pow2[0] = pow3[0] = pow5[0] = 1L;
        for (int i=1; i<=31; ++i) pow2[i] = 1L << i;
        for (int i=1; i<=20; ++i) pow3[i] = pow3[i-1] * 3L;
        for (int i=1; i<=13; ++i) pow5[i] = pow5[i-1] * 5L;

    }

    int nthUglyNumber(int n) {
        vector<int> ret;
        init();

        for (int i=0; i<=31; ++i) {
            for (int j=0; j<=20; ++j) {
                for (int k=0; k<=13; ++k) {
                    long long v = pow2[i] * pow3[j];
                    if (v > maxv) break;
                    v *= pow5[k];
                    if (v > maxv) break;
                    ret.emplace_back((int)v);
                }
            }
        }
        sort(ret.begin(), ret.end());
        for (int i=0; i<ret.size(); ++i) {
            printf("%d ", ret[i]);
        }
        printf("\n num = %d\n", ret.size());
        return ret[n - 1];
    }
};
// @lc code=end

