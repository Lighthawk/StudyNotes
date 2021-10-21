## String

```c++
# string 排序，static 不可少

static bool cmp(const string &a, const string &b) {
    if (a.size() == b.size()) return a > b;
    return a.size() > b.size();
}
string kthLargestNumber(vector<string>& nums, int k) {
    sort(nums.begin(), nums.end(), cmp);
    return nums[k-1];
}

```

