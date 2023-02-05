/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */


// @lc code=start
class Solution {
public:
    #define clr(a, b) memset(a, b, sizeof(a))
    int hs[26];
    int hx[26];
    const int maxv = 26;
    bool checkSame() {
        for (int i=0; i<maxv; ++i) {
            if (hs[i] != hx[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        clr(hs, 0);
        clr(hx, 0);
        int l1 = s1.size();
        int l2 = s2.size();
        if (l2 < l1) return false;

        for (int i=0; i<l1; ++i) {
            hs[s1[i] - 'a']++;
            hx[s2[i] - 'a']++;
        }
        if (checkSame()) return true;
        for (int i=l1; i<l2; ++i) {
            hx[s2[i] - 'a']++;
            hx[s2[i-l1] - 'a']--;
            if (checkSame()) return true;
        }
        return false;
    }
};
// @lc code=end

