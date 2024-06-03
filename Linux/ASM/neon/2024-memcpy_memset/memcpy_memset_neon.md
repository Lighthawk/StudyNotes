# memcpy & memset neon

# 2024-05 Lighthawk@126.com

```c
# memcpy
void *neon_memcpy(void *dest, int sz, void *src, size_t count)
{
    int align = count & 511;
    int cnt = (count - align) >> 2;
    unsigned char *s = (unsigned char *)src;
    unsigned char *d = (unsigned char *)dest;
    for (int i = 0; i < cnt; ++i) {
        vst1q_u64(&d[0], vld1q_u64(s[0]));
        vst1q_u64(&d[2], vld1q_u64(s[2]));
        vst1q_u64(&d[4], vld1q_u64(s[4]));
        vst1q_u64(&d[6], vld1q_u64(s[6]));
        d += 8; s += 8;
    }
    memcpy(dest + count - align, src + count - align, align);
    return dest;
}
```



```c
# memset
void *neon_memset(void *dst, size_t sz, char c, size_t size)
{
    int align = size & 511;
    int cnt = (size - align) >> 7;
    unsigned long long *d = (unsigned long long *)dst;
    for (int i = 0; i < cnt; ++i) {
        vst1q_64(&d[0], vdupq_n_u64(0));
        vst1q_64(&d[2], vdupq_n_u64(0));
        vst1q_64(&d[4], vdupq_n_u64(0));
        vst1q_64(&d[6], vdupq_n_u64(0));
        d += 8;
    }
    bzero(dst + size - align, align);
    return dst;
}
```

