#include <stdio.h>
#include <string.h>
#include "hw7-3.h"

void ParsingData(char* command, char* string1, char* string2) {
    // 初始化string1和string2
    string1[0] = '\0';
    string2[0] = '\0';

    // 使用strchr找到等號的位置
    char* equal_sign = strchr(command, '=');
    if (equal_sign != NULL) {
        // 分割command成string1和string2
        size_t len1 = equal_sign - command; // string1的長度
        strncpy(string1, command, len1);   // 複製string1的內容
        string1[len1] = '\0';              // 加上字串結尾符號

        // 去除string1末尾的空格
        char* end = string1 + strlen(string1) - 1;
        while (end >= string1 && *end == ' ') {
            *end = '\0';
            end--;
        }

        // 取得等號後的部分作為string2，並跳過多餘的空格
        char* start = equal_sign + 1;
        while (*start == ' ') {
            start++;
        }
        strcpy(string2, start);
    }
}
