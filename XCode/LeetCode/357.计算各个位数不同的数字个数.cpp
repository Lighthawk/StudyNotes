// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem357.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
public:
    int hs[12];
    int dfs(int deep, int n) {
        if (deep > n) return 1;

        int sum = 0;
        if (deep == 1) {
            for (int i=1; i<=9; ++i) {
                hs[i] = 1;
                sum += dfs(deep + 1, n);
                hs[i] = 0;
            }
        } else {
            for (int i=0; i<=9; ++i) {
                if (hs[i] == 0) {
                    hs[i] = 1;
                    sum += dfs(deep + 1, n);
                    hs[i] = 0;
                }
            }
        }

        return sum;
    }

    int countNumbersWithUniqueDigits(int n) {
        int ret = 1;
        
        for (int i=1; i<=n; ++i) {
            memset(hs, 0, sizeof(hs));
            ret += dfs(1, i);
        }
        return ret;
    }
};
// @lc code=end

