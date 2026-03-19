#include <stdio.h>

int main() {
    int a, b, c, amount;

    scanf("%d-%d-%d", &a, &b, &c);

    if (a < b) amount += 50;
    if ((a + b) < c) amount += 150;
    if (a == c) amount += 100;
    if (a == b && a == c && b == c) amount += 300;

    printf("%d\n", amount);
    return 0;
}