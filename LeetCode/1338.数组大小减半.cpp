/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 */

// @lc code=start
class Solution {
public:
    int hs[100001];
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), minv = 0x3f3f3f3f, maxv = -1;
        memset(hs, 0, sizeof(hs));
        for (int i=0; i<n; ++i) {
            hs[arr[i]]++;
            minv = min(minv, arr[i]);
            maxv = max(maxv, arr[i]);
        }

        vector<int> t;
        for (int i=minv; i<=maxv; ++i) {
            if (hs[i]) t.emplace_back(hs[i]);
        }
        sort(t.begin(), t.end());
        int len = t.size(), ret = 0, sum = 0;
        for (int i=len-1; i>=0 && sum<n/2; i--) {
            ret++;
            sum += t[i];
        }
        return ret;
    }
};
// @lc code=end

