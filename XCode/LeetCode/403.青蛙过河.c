/*
 * @lc app=leetcode.cn id=403 lang=c
 *
 * [403] 青蛙过河
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int* allocv(int len, int iv) {
    int* v = (int *)malloc(sizeof(int) * len);
    memset(v, iv, sizeof(int) * len);
    return v;
}

int **allocv2d(int row, int col, int iv) {
    int **v = (int **)malloc(sizeof(int *) * row);
    for (int i=0; i<row; ++i) {
        v[i] = allocv(col, iv);
    }
    return v;
}

int **allocv2d_special(int row, int col, int iv) {
    int **v = (int **)malloc(sizeof(int *) * row);
    for (int i=0; i<row; ++i) {
        v[i] = allocv(i + 2, iv);
    }
    return v;
}

int check(int v, int *s, int n) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (s[mid] == v) {
            return mid;
        } else if (s[mid] > v) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int hasIdx(int **dp, int idx, int jump) {
    int n = dp[idx][0];
    for (int i=1; i<=n; ++i) {
        if (dp[idx][i] == jump) return i;
    }
    return -1;
}

bool canCross(int* s, int n){
    if (n == 2) return s[1] == 1;
    if (n > 2 && s[1] != 1) return false;
 
    int **dp = allocv2d_special(n, n, 0);
    qsort(s, n, sizeof(int), cmp);
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i=1; i<n; ++i) {
        int j = i - 1;
        int kn = dp[j][0];
        for (int k=1; k<=kn; ++k) {
            for (int offset=-1; offset<=1; ++offset) {
                int jump = dp[j][k] + offset;
                int pos = s[j] + jump;
                if (jump <= 0 && pos < s[i]) {
                    continue;
                }
                int idx = check(pos, s, n);
                if (idx == -1) continue;
                if (hasIdx(dp, idx, jump) == -1) {
                    dp[idx][0] ++;
                    dp[idx][dp[idx][0]] = jump;
                }
            }
        }
    }
    bool flag = dp[n-1][0] > 0;
    free(dp);
    return flag;
}


// @lc code=end

