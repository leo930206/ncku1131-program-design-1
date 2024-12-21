#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw7-2.h"

// getUserInput function
char* getUserInput() {
    static char input[21]; // 保證輸入不超過 20 字元
    while (1) {
        // 提示用戶輸入
        fgets(input, 21, stdin);

        // 移除結尾的換行符號
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // 驗證指令是否符合格式
        char* equal_sign = strchr(input, '=');
        if (equal_sign == NULL && strcmp(input, "exit") != 0) {
            continue;
        }

        // 如果有等號，檢查格式
        if (equal_sign != NULL) {
            char string1[9], string2[9];
            int res = sscanf(input, "%8[^=]=%8[^=]", string1, string2);
        }

        // 如果是 "exit"，直接返回
        return input;
    }
}

// printAllInput function
void printAllInput(char command[51][21], int command_cnt) {
    for (int i = 0; i < command_cnt; i++) {
        printf("%s\n", command[i]);
    }
}