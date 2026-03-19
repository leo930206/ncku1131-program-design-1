#include <stdio.h>

int main() {
    int a, b, c;
    int x=0, y=0, z=0;

    scanf("%d %d %d", &a, &b, &c);
    while (a < 1 || b < 1 || c < 1 || a > 10 || b > 10 || c > 10) scanf("%d %d %d", &a, &b, &c);

    if (a == 1 || b == 1 || c == 1) x++;
    if (a == 2 || b == 2 || c == 2) y++;
    if (a == 3 || b == 3 || c == 3) z++;

    int space = 0; // 控制空格輸出

    if (x == 0) {
        printf("1");
        space++;
    }
    if (y == 0) {
        if (space > 0) printf(" "); 
        printf("2");
        space++;
    }
    if (z == 0) {
        if (space > 0) printf(" "); 
        printf("3");
    }
    if (x != 0 && y != 0 && z != 0) printf("Oh, Fried Shrimp, you're amazing!");
    printf("\n");

    return 0;
}
