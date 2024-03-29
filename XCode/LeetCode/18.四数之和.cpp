/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n <= 3) return ret;

        sort(nums.begin(), nums.end());

        for (int i=0; i<n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            
            for (int j=i+1; j<n-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                
                int v = nums[i] + nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int u = nums[l] + nums[r];
                    if (u + v == target) {
                        ret.emplace_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++; r--;
                    } else if (u + v > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ret;
    }
};

