#include <stdio.h>
#include <pthread.h>
//#include "calc.S"

#define uint8_t unsigned char
#define int32_t int
#define ulong64_t unsigned long long
#define maxn 64
#define pthread_num 1
#define cycle_num (1 << 20)

extern int32_t Simu_McCopyWidthEq8_AArch64_neon(
    uint8_t* pSrc,          // x0
    int32_t iSrcStride,     // x1
    uint8_t* pDst,          // x2
    int32_t iDstStride,     // x3
    ulong64_t iHeight         // x4
);

uint8_t sStr[maxn + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5,
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5,
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5,
                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                          0, 1, 2, 3, 4, 5};
uint8_t dStr[maxn + 1] = {0};

int func(int32_t tid) {
    int32_t ss = 0;
    int32_t dd = 0;
    ulong64_t h = (1L << 20);

    for (int i=0; i<cycle_num; ++i) {
        int32_t v = Simu_McCopyWidthEq8_AArch64_neon(sStr, ss, dStr, dd, h);
        // for (int i=0; i<maxn; ++i) {
        //     sStr[i] += '0';
        //     dStr[i] += '0';
        // }
        // sStr[maxn] = '\0';
        // dStr[maxn] = '\0';
        if (v != h)
            printf("[%04d] %s %s %d\n", tid, sStr, dStr, v);
    }
}

int main () {
    pthread_t threads[pthread_num];
    for (int i=0; i<pthread_num; ++i) {
        int32_t status = pthread_create(&threads[i], NULL, (void*)func, i);
    }
    for (int i=0; i<pthread_num; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

