#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    float *result = (float*)&N;
    printf("%.23e\n", *result);

    return 0;
}

/* 

一字串 32 bits 數字 00000000100000000000000000000000，有兩種解讀方式
假設這是 int : 2^23
假設這是 float : 1.17549435082228750796874e-38

這個 Program 就是輸入一個 int 然後輸出 float

*/