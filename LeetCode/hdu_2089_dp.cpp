#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 20
#define maxm 10

#define clr(a, b) memset(a, b, sizeof(a))

int dp[maxn][maxm], v[maxn];


int dfs(int pos, int state, bool lead, bool limit) {
    if (pos == -1) return 1;

    if (!lead && !limit && dp[pos][state]!=-1) return dp[pos][state];
    int ret = 0;
    int up = limit ? v[pos] : 9;
    for (int i=0; i<=up; ++i) {
        if (i == 4) continue;
        if (state == 6 && i == 2) continue;
        ret += dfs(pos-1, i, lead && i == 0, limit && i == v[pos]); // limit && i == up
    }
    if (!lead && !limit) dp[pos][state] = ret;
    return ret;
}

int solve(int x) {
    int pos = 0;
    clr(v, -1);
    while (x) {
        v[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, 0, true, true);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;

        clr(dp, -1);
        printf("%d\n", solve(m) - solve(n-1));
    }
    return 0;
}

