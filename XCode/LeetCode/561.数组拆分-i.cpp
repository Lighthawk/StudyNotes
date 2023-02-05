/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i=0; i<n; i+=2) {
            ret += min(nums[i], nums[i+1]);
        }
        return ret;
    }
};
// @lc code=end

