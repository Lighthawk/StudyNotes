#### 690.员工的重要性（树形搜索，hash索引）

* ##### 非常简单的题目，不知道为啥，Leetcode 总是写的代码量过高，时间复杂度也难以降下来，C++ 数据结构使用过于繁琐，故用题解写法总结。这题比较典型

```c++
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
```

```c++
// C++ dfs
class Solution {
public:
    unordered_map<int, Employee *> mp;

    int dfs(int id) {
        Employee *employee = mp[id];
        int total = employee->importance;
        for (int subId : employee->subordinates) {
            total += dfs(subId);
        }
        return total;
    }
    
    int getImportance(vector<Employee *> employees, int id) {
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
};

```

```c++
// C++ bfs
class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> mp;
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }

        int total = 0;
        queue<int> que;
        que.push(id);
        while (!que.empty()) {
            int curId = que.front();
            que.pop();
            Employee *employee = mp[curId];
            total += employee->importance;
            for (int subId : employee->subordinates) {
                que.push(subId);
            }
        }
        return total;
    }
};
```

```c++
// QAQ 我的 dfs 写法

class Solution {
public:
    void dfs_sub(vector<Employee*> &employees, vector<int> &es, int id) {
        int len = employees.size();
        
        for (int i=0; i<len; ++i) {
            if (employees[i]->id == id) {
                // es.emplace_back(id);
                for (int j=0; j<employees[i]->subordinates.size(); ++j) {
                    es.emplace_back(employees[i]->subordinates[j]);
                    dfs_sub(employees, es, employees[i]->subordinates[j]);
                }
            }
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        if (employees.size() == 0) return 0;
    
        int len = employees.size();
        vector<int> es;
        es.emplace_back(id);
        dfs_sub(employees, es, id);
        printf("size=%d \n", es.size());
        for (int i=0; i<es.size(); ++i) {
            printf("%d ", es[i]);
        }
        printf("\n");
        for (int i=0; i<es.size(); ++i) {
            for (int j=0; j<len; ++j) {
                if (es[i] == employees[j]->id) {
                    ret += employees[j]->importance;
                }
            }
        }
        return ret;
    }
};
```

