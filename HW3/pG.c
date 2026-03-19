#include <stdio.h>

int main() {
    long long a, b;
    long long max = 9223372036854775807ll;  // 64位 long long int 最大值
    long long min = -9223372036854775807ll - 1;  // 64位 long long int 最小值
    // -9223372036854775808LL 會 Overflow 因為電腦是先讀數字再讀正負

    scanf("%lld %lld", &a, &b);

    if ((a >= 0 && b < 0) || (b >= 0 && a < 0)) {   // a b 一正一負
        printf("No\n");
    }

    if (a >= 0 && b >= 0) {      // a b 都是正數
        if (a > max - b) {       // 很厲害的寫法！！ (a + b > max)
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    if (a < 0 && b < 0) {       // a b 都是負數
        if (a < min - b) {       // 很厲害的寫法！！ (a + b < min)
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
