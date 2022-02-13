// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem740.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
public:
    struct stat {
        int n, s;
        stat(int n,int s):n(n),s(s){}
    };
    static bool cmp(const stat &a, const stat &b) {
        return a.s > b.s;
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<stat> st;
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[0];
        for (int i=1; i<l; ++i) {
            if (nums[i] == nums[i-1]) sum += nums[i];
            else {
                sum = nums[i];
                stat x(nums[i-1], sum);
                st.emplace_back(x);
            }
        }
        stat x(nums[l-1], sum);
        st.emplace_back(x);
        sort(st.begin(), st.end(), cmp);

        int len = st.size();
        int lft = 0, rst = lft + 1;
        int ret = 0;
        while (rst < len) {
            rst++;
            if (rst < len && st[rst].n == st[lft].n + 1) continue;
            else {
                int s1 = 0, s2 = 0;
                for (int i=lft; i<rst; ++i) {
                    if (i & 1) s1 += st[i].s;
                    else s2 += st[i].s;
                }
                ret += max(s1, s2);
                lft = rst;
            }
        }
        // int s1 = 0, s2 = 0;
        // for (int i=lft; i<rst; ++i) {
        //     if (i & 1) s1 += st[i].s;
        //     else s2 += st[i].s;
        // }
        // ret += max(s1, s2);
        return ret;
    }
};
// @lc code=end

