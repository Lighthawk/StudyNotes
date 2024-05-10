#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define maxn (1L << 20)
#define cycle_num (1L << 20)

void func() {
    double sum1 = 0.0, sum2 = 0.0;
    for (int i=0; i<cycle_num; ++i) {
        float r = (float)rand() / (1.0 * (1 << 30) + 1);
        if (r > 1.0) {
            sum1 += r;
        } else {
            sum2 -= r;
        }
    }
    // printf("%.2f %.2f\n", sum1, sum2);
}

int main() {
    srand((unsigned)time(NULL));
    for (int i=0; i<cycle_num; ++i) {
        func();
    }
    
    return 0;
}


