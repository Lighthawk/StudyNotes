Trie

```c++
# 自己规规矩矩的 trie，string 如果改为引用，耗时更少，但最后用例还是超时
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
        if (st.find(s) != st.end()) return;

        if (idx >= s.size()) {
            if (cnt >= 2) {
                ret.emplace_back(s);
                st.insert(s);
            }
            return;
        }

        Trie *w = tree;
        for (int i=idx; i<s.size(); ++i) {
            if (w->son[s[i] - base] == nullptr) return;
            if (w->son[s[i] - base]->terminal == true) dfs(s, i + 1, cnt + 1, ret, st);
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

```

```c++
# 472 非常卡时间的 trie 题目，引用技巧较多
struct TrieNode {
    char val;
    bool isend;
    map<char, TrieNode*> next;
    TrieNode(char val, bool isend) : val(val), isend(isend) {};
    TrieNode() : val(' ') {};
};

bool cmp(const string& l, const string& r) {
    return l.size() < r.size();
}

class Solution {
public:
    TrieNode root;

    void insert(string word) {
        TrieNode* curNode = &root;
        for (auto c : word) {
            if (curNode->next.count(c) == 0) {
                curNode->next[c] = new TrieNode(c, false);
            }
            curNode = curNode->next[c];
        }
        curNode->isend = true;
    }

    bool isInTrie(string word) {
        TrieNode* curNode = &root;
        for (auto c : word) {
            if (curNode->next.count(c) == 0) {
                return false;
            }
            curNode = curNode->next[c];
        }
        return curNode->isend;
    }

    bool dfs(string& word, int start, vector<int>& visited) {
        int sz = word.size();
        TrieNode* curNode = &root;
        if (start == sz) {
            return true;
        }
        if (visited[start] == 1) {
            return false;
        }
        for (int i = start; i < sz; i++) {
            if (curNode->next.count(word[i]) == 0) {
                break;
            }
            curNode = curNode->next[word[i]];
            if (curNode->isend) {
                if (dfs(word, i + 1, visited)) {
                    return true;
                }
            }
        }
        visited[start] = 1;
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), cmp);

        for (auto s : words) {
            if (s.size() == 0) {
                continue;
            }
            vector<int> visited(s.size(), 0);
            if (dfs(s, 0, visited)) {
                res.push_back(s);
            }
            insert(s);
        }
        return res;
    }
};
