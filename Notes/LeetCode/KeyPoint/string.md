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

// 排序后 a+b 大的在前
static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
}

// 整数转字符串
string ret = to_string(int_value);

// 字符串转整数
string s = "12";
int a = atoi(s);

// 原生 c++ 没有字符串 split 函数


```

