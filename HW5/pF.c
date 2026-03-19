#include <stdio.h>

int main() {
    // Ipunt: n車輛數 q查幾次 k最低人數要求
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);

    // Input: 每台車的人數
    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        if (p[i] < k) p[i] = 1;  // 違反的車輛標為 1
        if (p[i] >= k) p[i] = 0;  // 通過的車輛標為 0
    }

    // 計算好所有前綴和，方便等等使用 prefix sum
    int S[n + 1];
    S[0] = 0;
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + p[i - 1];
    }

    // 要查詢的車輛範圍
    int l, r;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", S[r] - S[l - 1]);
    }
}