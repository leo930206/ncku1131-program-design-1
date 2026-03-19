#include <string.h>
#include "hw7-4.h"

char* getAnswer1(char* testcase) {
    static char result[51];
    int len = (int)strlen(testcase);
    int idx = 0; // result的寫入位置
    
    for (int i = 0; i < len; i++) {
        if (testcase[i] == 'a') {
            // 計算連續 a 的數量
            int count = 1;
            int j = i + 1;
            while (j < len && testcase[j] == 'a') {
                count++;
                j++;
            }

            // 若 count == 1，保留該 'a'，否則不加入 result 中
            if (count == 1) {
                result[idx++] = 'a';
            }
            // 將 i 跳過這段連續 a 的最後一個位置
            i = j - 1;

        } else {
            // 非 'a' 字元直接加入 result
            result[idx++] = testcase[i];
        }
    }

    result[idx] = '\0'; // 字串結尾
    return result;
}