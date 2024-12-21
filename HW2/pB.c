#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a, b, c, d;

    FILE *fread = fopen(argv[1], "r");
    fscanf(fread, "%d %d %d %d", &a, &b, &c, &d);
    fclose(fread);

    int denominator = (a * d) + (b * c);
    int numerator = b * d;

    FILE *fwrite = fopen("answer.txt", "w");
    fprintf(fwrite, "%d/%d", denominator, numerator);
    fclose(fwrite);

    return 0;
    }
