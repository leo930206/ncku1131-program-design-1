#include <stdio.h>
#include "pC.h"

void f(int n, int *ans) {
    if (n == 0) {
        *ans = 0; 
        return;
    }
    if (n == 1) {
        *ans = 1; 
        return;
    }

    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;  
        b = temp;
    }
    *ans = b; 
}
