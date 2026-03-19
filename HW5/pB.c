#include <stdio.h>

int main() {
    // Input
    int n;
    scanf("%d", &n);

    // 邊Input邊判斷最大範圍建立陣列
    int l[n], r[n], max_time = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        if (r[i] > max_time) max_time = r[i];
    }

    // 宣告一個足夠大的陣列來計算每個時間點的範圍重疊數
    int count[max_time + 1];
    for (int i = 0; i <= max_time; i++) {
        count[i] = 0;
    }

    // 更新每個範圍內的計數
    for (int i = 0; i < n; i++) {
        for (int j = l[i]; j < r[i]; j++) {
            count[j]++;
        }
    }

    // 找出最大重疊數
    int max_vehicle = 0;
    for (int i = 0; i <= max_time; i++) {
        if (count[i] > max_vehicle) {
            max_vehicle = count[i];
        }
    }

    // 輸出最大重疊數
    printf("%d\n", max_vehicle);

    return 0;
}
