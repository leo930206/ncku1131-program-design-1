#include <stdio.h>

int main() {
    int m, k, sum, count=0;
    
    scanf("%d", &m);

    scanf("%d", &k);
    while(sum <= m){
        sum += k;
        count ++;
        scanf("%d", &k);
    }

    printf("Fried Pork!!!!\n%d\n", count);
    return 0;
}