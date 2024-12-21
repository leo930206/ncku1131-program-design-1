#include <stdio.h>
#include <stdlib.h>  // 使用 abs 函數 求絕對值

int func(int x, int y, int z);

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max = func(a, b, c);
    if (func(a, c, b) > max) max = func(a, c, b);
    if (func(b, a, c) > max) max = func(b, a, c);
    if (func(b, c, a) > max) max = func(b, c, a);
    if (func(c, a, b) > max) max = func(c, a, b);
    if (func(c, b, a) > max) max = func(c, b, a);

    printf("%d\n", max);
}

int func(int x, int y, int z) {
    int a = ((x + z) ^ (y - z)) - (x & z & (y & 2024) | abs(z-y));
    return a;
}