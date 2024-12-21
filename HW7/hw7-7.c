#include "hw7-7.h"

void GeneratingTest(int target_len, char all_testcase[][11]) {
    int total = 1;
    for (int i = 0; i < target_len; i++) {
        total *= 3;
    }

    for (int i = 0; i < total; i++) {
        int num = i;
        for (int j = target_len - 1; j >= 0; j--) {
            int rem = num % 3;
            char c;
            if (rem == 0) c = 'a';
            else if (rem == 1) c = 'b';
            else c = 'c';

            all_testcase[i][j] = c;
            num /= 3;
        }
        all_testcase[i][target_len] = '\0';  // 字串結尾
    }
}
