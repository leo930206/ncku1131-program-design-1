#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {   // 處理int
        int X;
        scanf("%d", &X);

        for (int i = 31; i >= 0; i--) {
            int bit = (X >> i) & 1;
            printf("%d", bit);
        }
        printf("\n");
    }

    if (N == 2) {   // 處理float
        float X;
        scanf("%f", &X);

        // 取得符號位
        int sign = (X < 0) ? 1 : 0;
        printf("%d", sign);

        // 取得絕對值
        float absX = fabs(X);

        // 計算指數
        int exponent = 0;
        while (absX >= 2.0f) {
            absX /= 2.0f;
            exponent++;
        }
        while (absX < 1.0f && absX != 0.0f) {
            absX *= 2.0f;
            exponent--;
        }
        int exponent_bits = exponent + 127; // 加上偏移量

        // 輸出指數位
        for (int i = 7; i >= 0; i--) {
            int bit = (exponent_bits >> i) & 1;
            printf("%d", bit);
        }

        // 計算尾數位
        absX -= 1.0f; // 移除隱含的 1
        for (int i = 1; i <= 23; i++) {
            absX *= 2;
            if (absX >= 1.0f) {
                printf("1");
                absX -= 1.0f;
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}
