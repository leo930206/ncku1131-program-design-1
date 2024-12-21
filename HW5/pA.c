#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int s[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] <= 60) {
            count++;
            while (s[i] <= 60) {
                i++;
            }
        }
    }

    printf("%d\n", count);
}