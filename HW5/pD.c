#include <stdio.h>

int main() {
    // Input
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 計算好所有前綴和，方便等等使用 prefix sum
    //  S[0] = 0
    //  S[1] = a[0]
    //  S[2] = a[0] + a[1] 
    //  ...
    //  S[n] = a[0] + a[1] + ... + a[n-1]
    long long S[n + 1];  // 因為是前綴和，所以有可能很大，用 long long 比較保險
    S[0] = 0;
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i - 1];
    }

    // 讀取查詢
    int q;
    scanf("%d", &q);

    // 處理查詢
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", S[r] - S[l - 1]);
    }

    return 0;
}
