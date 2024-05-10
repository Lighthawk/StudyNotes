#include "common.S"

ASM_FUNC_BEGIN Simu_McCopyWidthEq8_AArch64_neon
    mov x5, 0
simu_w8_copy_loop:
    ld1 {v0.8b}, [x0], x1
    st1 {v0.8b}, [x2], x3

    ld1 {v1.8b}, [x0], x1
    st1 {v1.8b}, [x2], x3

    add x5, x5, #1
    sub x4, x4, #1
    cbnz x4, simu_w8_copy_loop
    
    mov x0, x5
ASM_FUNC_END
