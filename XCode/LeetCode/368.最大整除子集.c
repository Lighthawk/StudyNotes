/*
 * @lc app=leetcode.cn id=368 lang=c
 *
 * [368] 最大整除子集
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int getmax(const int a, const int b) {
    return a > b ? a : b;
}

int* allocv(int len) {
    int *v = (int *)malloc(sizeof(int) * len);
    memset(v, 0x00, sizeof(int) * len);
    return v;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    int n = numsSize;
    if (n <= 1) {
        *returnSize = n;
        return nums;
    }

    int *dp = allocv(n);
    int *pre = allocv(n);

    // return nums;
    qsort(nums, n, sizeof(int), cmp);
    dp[0] = 1;
    pre[0] = -1;
    
    int maxLen = 1;
    int maxIdx = 0;
    for (int i=1; i<n; ++i) {
        dp[i] = 1;
        for (int j=0; j<i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if (maxLen < dp[i]) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    int *ret = allocv(maxLen);
    int idx = maxIdx;
    *returnSize = maxLen;

    while (maxLen > 0) {
        maxLen--;
        ret[maxLen] = nums[idx];
        idx = pre[idx];
    }
    return ret;
}
// @lc code=end
