// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem150.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int>stk;
        while (!stk.empty()) stk.pop();

        for (int i=0; i<len; ++i) {
            int v;
            string ss = tokens[i];
            if ((ss[0] >= '0' && ss[0] <= '9') || ss.size() > 1) {
                v = std::stoi(ss);
                stk.push(v);
            } else {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (ss[0] == '+') v = v1 + v2;
                if (ss[0] == '-') v = v2 - v1;
                if (ss[0] == '*') v = v1 * v2;
                if (ss[0] == '/') v = v2 / v1;
                stk.push(v);
            }
        }
        return stk.top();
    }
};
// @lc code=end

