#include <stdio.h>
#include <string.h>
#include "hw7-1.h"

int GameStart() {
    printf("Welcome to the game A = B, please select the level\n");

    char str[100];
    scanf("%s", str);

    if (strcmp(str, "1") != 0 && strcmp(str, "2") != 0) {
        return -1;
    }

    if (strcmp(str, "1") == 0) return 1;
    if (strcmp(str, "2") == 0) return 2;
}