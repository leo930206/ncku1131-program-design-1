#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    while(a != 0) {
        b *= 10;
        b += (a % 10);
        a /= 10;
    }

    printf("%d\n", b);

    return 0;
}
