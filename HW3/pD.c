#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int ans = 0;
    while(a != 0) {
        ans *= 10;
        ans += (a % 10);
        a /= 10;
    }

    printf("%d\n", ans);

    return 0;
}