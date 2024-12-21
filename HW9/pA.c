#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> // 用於浮點數最大值檢查

// 定義函數指標類型 F
typedef double (*F)(double, int);

// 基本運算函數
double power(double x, int n) {
    return pow(x, n);
}

double multiply(double x, int n) {
    return x * n;
}

double divide(double x, int n) {
    if (n == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return x / (double)n; // 確保為浮點數運算
}

// 複合運算函數
double powerpower(F func, double x, int n, int m) {
    double result = func(x, n);
    result = pow(result, m);
    if (result > DBL_MAX || result < -DBL_MAX) {
        fprintf(stderr, "Overflow error in powerpower().\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

double powermultiply(F func, double x, int n, int m) {
    double result = func(x, n) * m;
    if (result > DBL_MAX || result < -DBL_MAX) {
        fprintf(stderr, "Overflow error in powermultiply().\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

double powerdivide(F func, double x, int n, int m) {
    if (m == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    double result = func(x, n) / m;
    if (result > DBL_MAX || result < -DBL_MAX) {
        fprintf(stderr, "Overflow error in powerdivide().\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s x n m\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 從命令列參數讀取 x, n, m
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);

    // 驗證輸入參數
    if (n < 0 || m < 0) {
        fprintf(stderr, "Error: n and m must be non-negative integers.\n");
        return EXIT_FAILURE;
    }

    // 計算並輸出結果
    printf("%f\n", powerpower(power, x, n, m));       // (x^n)^m
    printf("%f\n", powerpower(multiply, x, n, m));   // (x*n)^m
    printf("%f\n", powerpower(divide, x, n, m));     // (x/n)^m

    printf("%f\n", powermultiply(power, x, n, m));   // (x^n)*m
    printf("%f\n", powermultiply(multiply, x, n, m)); // (x*n)*m
    printf("%f\n", powermultiply(divide, x, n, m));  // (x/n)*m

    printf("%f\n", powerdivide(power, x, n, m));     // (x^n)/m
    printf("%f\n", powerdivide(multiply, x, n, m)); // (x*n)/m
    printf("%f\n", powerdivide(divide, x, n, m));   // (x/n)/m

    return EXIT_SUCCESS;
}