/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n <= 2) return ret;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n-2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    ret.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                } else if (nums[l] + nums[r] + nums[i] > 0) {
                    r --;
                } else {
                    l ++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

