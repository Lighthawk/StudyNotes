#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int gv(vector<vector<int>>& prf, int r, int y) {
        if (y < r) return prf[r][y];
        return prf[r][y-1];
    }
    int check(vector<vector<int>>& prf, int x, int y, int u, int v) {
        int ret = 0;
        int xu = gv(prf, x, u), xy = gv(prf, x, y), ux = gv(prf, u, x), uv = gv(prf, u, v);
        int yv = gv(prf, y, v), yx = gv(prf, y, x), vy = gv(prf, v, y), vu = gv(prf, v, u);
        if (xu > xy && ux > uv) {
            ret ++;
        }
        return ret;
    }
    int unhappyFriends(int n, vector<vector<int>>& prf, vector<vector<int>>& pairs) {
        int np = n >> 1;
        int ret = 0;
        for (int i=0; i<np; ++i) {
            for (int j=i+1; j<np; ++j) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                ret += check(prf, x, y, u, v);
                ret += check(prf, x, y, v, u);
                ret += check(prf, y, x, u, v);
                ret += check(prf, y, x, v, u);
            }
        }
        return ret;
    }
};
int main() {
    vector<vector<int>> pairs;
    vector<vector<int>> prf;
    vector<int>a;
    vector<int>b;
    vector<int>c;
    vector<int>d;
    int n = 4;

    a.push_back(1);
    a.push_back(3);
    a.push_back(2);

    b.push_back(2);
    b.push_back(3);
    b.push_back(0);

    c.push_back(1);
    c.push_back(3);
    c.push_back(0);

    d.push_back(0);
    d.push_back(2);
    d.push_back(1);

    prf.push_back(a);
    prf.push_back(b);
    prf.push_back(c);
    prf.push_back(d);

    vector<int>p1(2);
    vector<int>p2(2);
    p1[0] = 1;
    p1[1] = 3;
    p2[0] = 0;
    p2[1] = 2;
    pairs.push_back(p1);
    pairs.push_back(p2);
    Solution *ret = new Solution();
    int prt = ret->unhappyFriends(n, prf, pairs);
    printf("ret = %d\n", prt);
    return 0;
}