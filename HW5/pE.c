#include <stdio.h>

int check(int p[], int x, int k);

int main() {
    // Ipunt: n車輛數 q查幾次 k最低人數要求
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);

    // Input: 每台車的人數
    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Input: 要查詢的車輛範圍
    int l[n], r[n];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    // 輸出
    for (int i = 0; i < q; i++) {
        printf("%d\n", check(p, r[i], k) - check(p, l[i]-1, k));
    }
}

// 檢查範圍內有幾輛車違規
int check(int p[], int x, int k) {
    int count = 0;
    for  (int i = 0; i < x; i++) {
        if (p[i] < k) count++;
    }

    return count;
}