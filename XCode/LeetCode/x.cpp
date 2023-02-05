class Solution {
public:
    LLT m = 1000000007L;
    
    LLT pow2m(LLT x) {
        LLT ret = 1L;
        LLT tmp = 1L;
        while (x) {
            if (x & 1) {
                ret = (ret * tmp) % m;
            }
            tmp = (tmp * tmp) % m;
            x = x >> 1;
        }
        return ret;
    }
    LLT mulm(LLT x, LLT y) {
        return ((x % m) * (y % m)) % m;
    }
    LLT bisn(LLT x) {
        LLT ret = 0L;
        while (x) {
            ret ++;
            x = x >> 1;
        }
        return ret;
    }
    LLT summ(LLT x, LLT y) {
        return (x + y) % m;
    }
    int concatenatedBinary(int n) {
        LLT ret = 0;
        LLT sumbits = 0;
        for (LLT i=1L; i<=n; ++i) {
            LLT tmp = mulm(i, pow2m(sumbits));
            ret = summ(ret, tmp);
            LLT b = bisn(i);
            sumbits += b;
        }
        return ret;
    }
};