#include <stdio.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long c = -9223372036854775807LL - 1;
    // -9223372036854775808LL 會 Overflow 因為電腦是先讀數字再讀正負

    // 唯一特例
    if ((a == c) && (b == c)) {
        printf("-18446744073709551616\n");
        return 0;
    }

    // 一正一負
    if ((a >= 0 && b < 0) || (b >= 0 && a < 0)) {
        printf("%lld\n", a + b);
    }

    // 都是正
    if (a >= 0 && b >= 0) {
        unsigned long long x = a, y = b;
        printf("%llu\n", x + y);
    }

    // 都是負
    if (a < 0 && b < 0) {
        unsigned long long x = (a * -1), y = (b * -1);
        printf("-%llu\n", x + y);
    }

    return 0;
}
