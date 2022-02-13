/*
 * @lc app=leetcode.cn id=303 lang=c
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start



typedef struct {
    int sum;
    int sz;
    int idx;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *ret = (NumArray *)malloc(sizeof(NumArray) * numsSize);
    memset(ret, 0, sizeof(NumArray) * numsSize);

    for (int i=0; i<numsSize; ++i) {
        ret[i].sz = numsSize;
        ret[i].idx = i;
        ret[i].sum = i == 0 ? nums[i] : ret[i-1].sum + nums[i];
    }
    return ret;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sz = -1;
    if (obj == 0) return 0;
    else sz = obj[0].sz;
    if (j >= sz) j = sz - 1;
    if (i <= 0) return obj[j].sum;
    return obj[j].sum - obj[i-1].sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
// @lc code=end

