#include <stdio.h>
#include <string.h>
#include "hw7-6.h"

char* ProcessingCommand(char string1[51][21], char string2[51][21], char* testcase, int command_cnt, int test_mode) {
    static char result[51];
    strcpy(result, testcase); // 複製初始測資到 result

    for (int i = 0; i < command_cnt; i++) {
        char* s1 = string1[i];
        char* s2 = string2[i];
        int len1 = (int)strlen(s1);
        int len2 = (int)strlen(s2);

        // 不斷尋找並替換 s1 為 s2
        while (1) {
            char* pos = strstr(result, s1);
            if (!pos) {
                break; // 找不到 s1 就結束該指令的處理
            }

            // 先把後面多餘的部分存起來
            char temp[51];
            strcpy(temp, pos + len1);

            // 在pos處貼上s2，並將tail接回去
            memcpy(pos, s2, len2);
            pos[len2] = '\0';
            strcat(result, temp);

            // test_mode = 1 時，每次替換後印出中間結果
            if (test_mode == 1) {
                printf("%s\n", result);
            }
        }
    }

    return result;
}
