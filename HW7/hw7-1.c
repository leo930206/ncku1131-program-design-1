#include <stdio.h>
#include "hw7-1.h"

int GameStart() {
    printf("Welcome to the game A = B, please select the level\n");

    int x;
    if (scanf("%d", &x) != 1) { // 檢查是否成功讀取數字
        while (getchar() != '\n'); // 清空輸入緩衝區
        return -1;
    }

    if (x != 1 && x != 2) return -1;

    return x; 
}
