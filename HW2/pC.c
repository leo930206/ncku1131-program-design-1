#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c, d;
    char input1[100],input2[100];

    while (1) {
        printf("Please enter the name of the file to read from.\n");
        fgets(input1, sizeof(input1), stdin); // input file name (read)
        input1[strcspn(input1, "\n")] = 0;
        
        if (strcmp(input1, "exit") == 0) {
            break;
        }
        
        FILE *inputFile = fopen(input1, "r");
        if (inputFile == NULL) {
            printf("The file name does not exist.\n");
            continue;
        }
        
        printf("Please enter the name of the file to write the output to.\n");
        fgets(input2, sizeof(input2), stdin); // input file name (write)
        input2[strcspn(input2, "\n")] = 0;
        printf("Calculation complete!\n");
        
        FILE *fread = fopen(input1, "r");
        fscanf(fread, "%d %d %d %d\n", &a, &b, &c, &d);
        fclose(fread);

        int denominator = (a * d) + (c * b);
        int numerator = b * d;

        FILE *fwrite = fopen(input2, "w");
        fprintf(fwrite, "%d/%d\n", denominator, numerator);
    }

    return 0;
}

