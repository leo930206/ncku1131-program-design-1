#include <stdio.h>

long long int height[2001][2001];
long long int row_max[2001];
long long int col_max[2001];

int main() {
    long long int row, col;
    scanf("%lld %lld", &row, &col);

    // 初始化行最大值和列最大值為 0
    for (int i = 0; i < row; i++) row_max[i] = 0;
    for (int j = 0; j < col; j++) col_max[j] = 0;

    // 輸入矩陣並計算行和列的最大值
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%lld", &height[i][j]);
            if (height[i][j] > row_max[i]) row_max[i] = height[i][j];
            if (height[i][j] > col_max[j]) col_max[j] = height[i][j];
        }
    }

    // 計算最大增加總和
    long long int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int new_height = (row_max[i] < col_max[j]) ? row_max[i] : col_max[j];
            count += (new_height - height[i][j]);
        }
    }

    printf("%lld\n", count);
    return 0;
}