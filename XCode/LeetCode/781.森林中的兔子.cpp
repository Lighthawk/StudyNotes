/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int n = ans.size();
        if (n == 0) return 0;
        if (n == 1) return ans[0];

        sort(ans.begin(), ans.end());
        for (int i=0; i<n; ++i) ans[i]++;

        int cnt = 1, sum = 0;
        for (int i=0; i<n; ++i) {
            if (i == n-1 || ans[i] != ans[i+1]){
                sum += (cnt / ans[i]) * ans[i] + (cnt % ans[i] ? ans[i] : 0);
                cnt = 1;
            } else {
                cnt ++;
            }
        }
        return sum;
    }
};
// @lc code=end

