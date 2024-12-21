#include <stdio.h>

int main() {
    int N;
    int delta[1000000] = {0}; 

    scanf("%d", &N);

    int max_time = 0;
    for (int i = 0; i < N; i++) {
        int Li, Ri;
        scanf("%d %d", &Li, &Ri);
        delta[Li]++;     // 在進入時間增加車輛數
        delta[Ri]--;     // 在離開時間減少車輛數
        if (Ri > max_time) max_time = Ri;    // 計算最大時間
    }

    int max_vehicle = 0;
    int count = 0;
    for (int i = 0; i < max_time; i++) {   // 假設 max_time 是最大的離開時間 Ri，而 Ri 時間點的車輛已經離開了，因此不需要計算 i = max_time
        count += delta[i];
        if (count > max_vehicle) {
            max_vehicle = count;
        }
    }

    printf("%d\n", max_vehicle);

    return 0;
}
