/*
 * @lc app=leetcode.cn id=410 lang=c
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#define maxv 0x3f3f3f3f

int getmax(int a, int b) {
    return a > b ? a : b;
}
int getmin(int a, int b) {
    return a < b ? a : b;
}

bool check(int *s, int n, int v, int m) {
    int sum = 0, sn = 0;
    for (int i=0; i<n; ++i) {
        if (sum + s[i] <= v) {
            sum += s[i];
        } else {
            sum = s[i];
            sn ++;
        }
    }
    return sn + 1 <= m && sum <= v;
}

int splitArray(int* nums, int n, int m){
    int l = -1, r = 0, mid, ret = -1;
    for (int i=0; i<n; ++i) {
        l = getmax(l, nums[i]);
        r += nums[i];
    }

    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(nums, n, mid, m)) {
            r = mid - 1;
            ret = mid;
        } else {
            l = mid + 1;
        }
    }
    return ret;
}
// @lc code=end

