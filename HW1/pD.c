#include <stdio.h>

int main(){
    int num1, num2;
    char operator;
    scanf("%d %c %d",&num1 ,&operator ,&num2);

    printf("%d\n",(num1+num2)*(operator=='+')+(num1-num2)*(operator=='-')+(num1*num2)*(operator=='*'));

    return 0;
}
