#include <stdio.h>

int main() {
    int N, C, K;
    scanf("%d %d %d", &N, &C, &K);

    int count = 0;  // 記錄第 K 隻炸蝦得到的糖果數
    int direction = 1;  // 方向： 1從左到右 -1從右到左

    while (C > 0) {
        if (direction == 1) {
            // 從左到右
            for (int i = 1; i <= N && C > 0; i++) {
                if (i == K) {
                    count++;
                }
                C--;
            }
        } else {
            // 從右到左
            for (int i = N; i >= 1 && C > 0; i--) {
                if (i == K) {
                    count++;
                }
                C--;
            }
        }
        direction *= -1;  // 切換方向
    }

    printf("%d\n", count);
    return 0;
}
