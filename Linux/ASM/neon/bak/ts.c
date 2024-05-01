#include <stdio.h>
//#include "calc.S"

#define uint8_t unsigned char
#define int32_t int
#define maxn 64

extern void Simu_McCopyWidthEq8_AArch64_neon(
    uint8_t* pSrc,          // x0
    int32_t iSrcStride,     // x1
    uint8_t* pDst,          // x2
    int32_t iDstStride,     // x3
    int32_t iHeight         // x4
);

uint8_t sStr[maxn + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3};
uint8_t dStr[maxn + 1] = {0};

int main () {
    int32_t sstride = 2;
    int32_t dstride = 2;
    int32_t h = 2;

    Simu_McCopyWidthEq8_AArch64_neon(sStr, sstride, dStr, dstride, h);

    for (int i=0; i<maxn; ++i) {
        sStr[i] += '0';
        dStr[i] += '0';
    }
    sStr[maxn] = '\0';
    dStr[maxn] = '\0';
    printf("%s %s\n", sStr, dStr);

    return 0;
}
