// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem472.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
class Solution {
public:
    static const int base = 'a';
    static const int sonnum = 26;
    
    struct Trie {
        bool terminal;
        struct Trie *son[sonnum];
    };

    Trie *tree;
    Trie *newNode(){
        Trie *temp = new Trie();
        temp->terminal = false;
        for (auto x : temp->son) x = nullptr;
        return temp;
    }

    void insertWrod(string s) {
        Trie *w = tree;
        for (auto x : s) {
            if (w->son[x - base] == nullptr) w->son[x - base] = newNode();
            w = w->son[x - base];
        }
        w->terminal = true;
    }
    
    void dfs(string s, int idx, int cnt, vector<string> &ret, unordered_set<string> &st) {
        // if (st.find(s) != st.end()) return;
        if (idx == s.size()) {
            if (cnt >= 2) {
                ret.emplace_back(s);
                st.insert(s);
            }
            return;
        }

        Trie *w = tree;
        for (int i=idx; i<s.size(); ++i) {
            if (w->son[s[i] - base] == nullptr) return;
            if (w->terminal == true) dfs(s, i, cnt + 1, ret, st);
            w = w->son[s[i] - base];
        }
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        unordered_set<string> st;
        tree = newNode();

        for (auto s : words) insertWrod(s);
        for (auto s : words) dfs(s, 0, 0, ret, st);
        sort(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

