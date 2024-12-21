#include <string.h>
#include <stdlib.h>
#include "hw7-5.h"

int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* getAnswer2(char *testcase) {
    static char result[51]; // 使用靜態陣列
    strcpy(result, testcase); // 複製輸入字串至 result

    // 取得字串長度
    size_t len = strlen(result);

    // 使用 qsort 對字串進行排序
    qsort(result, len, sizeof(char), cmpChar);

    return result;
}