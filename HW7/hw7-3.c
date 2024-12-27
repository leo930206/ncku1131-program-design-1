#include <stdio.h>
#include <string.h>
#include "hw7-3.h"

void ParsingData(char* command, char* string1, char* string2) {
    // 初始化 string1 和 string2
    string1[0] = '\0';
    string2[0] = '\0';

    // 嘗試找到 " = " 作為分割點
    char* separator = strstr(command, " = ");
    if (separator != NULL) {
        // 計算 string1 的長度
        size_t len1 = separator - command;
        strncpy(string1, command, len1);
        string1[len1] = '\0'; // 添加字串結尾符號

        // string2 從 " = " 之後開始
        char* start2 = separator + 3; // 跳過 " = "
        strcpy(string2, start2);
    } else {
        // 若未找到 " = "，則尋找第一個 '='
        char* equal_sign = strchr(command, '=');
        if (equal_sign != NULL) {
            size_t len1 = equal_sign - command;
            strncpy(string1, command, len1);
            string1[len1] = '\0'; // 添加字串結尾符號

            // string2 從 '=' 之後開始
            char* start2 = equal_sign + 1;
            // 移除開頭的空格
            while (*start2 == ' ') start2++;
            strcpy(string2, start2);
        }
    }

    // 移除 string1 末尾的空格
    size_t len1 = strlen(string1);
    while (len1 > 0 && string1[len1 - 1] == ' ') {
        string1[len1 - 1] = '\0';
        len1--;
    }

    // 移除 string2 開頭和結尾的空格
    // 移除開頭的空格
    char* s = string2;
    while (*s == ' ') s++;
    memmove(string2, s, strlen(s) + 1);

    // 移除結尾的空格
    size_t len2 = strlen(string2);
    while (len2 > 0 && string2[len2 - 1] == ' ') {
        string2[len2 - 1] = '\0';
        len2--;
    }

    // 特殊處理：如果 string1 是空白的，且 string2 以 '=' 開頭
    if (strlen(string1) == 0 && strlen(string2) > 0 && string2[0] == '=') {
        strcpy(string1, "=");
        memmove(string2, string2 + 1, strlen(string2));
        // 再次移除 string2 開頭的空格
        s = string2;
        while (*s == ' ') s++;
        memmove(string2, s, strlen(s) + 1);
    }
}
