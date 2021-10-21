#### unordered_map 简单写法

##### 692. 前K个高频单词

```c++
// 官方写法
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            ++cnt[word];
        }
        vector<string> rec;
        for (auto& [key, value] : cnt) {
            rec.emplace_back(key);
        }
        sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        rec.erase(rec.begin() + k, rec.end());
        return rec;
    }
};
```



```c++
// 我的写法
class Solution {
public:
    struct node {
        string w;
        int c;
        node(string w, int c): w(w), c(c){}
    };
    struct cmp {
        bool operator()(const node &a, const node &b){
            if (a.c == b.c) return a.w > b.w;
            return a.c < b.c;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto w : words) {
            auto f = mp.find(w);
            if (f == mp.end()) mp.insert(make_pair(w, 1));
            else f->second++;
        }

        priority_queue<node, vector<node>, cmp> que;
        for (auto p : mp) {
            node x = node(p.first, p.second);
            que.push(x);
        }
        
        vector<string> ret;
        while (k--) {
            ret.emplace_back(que.top().w);
            que.pop();
        }
        return ret;
    }
};
```

