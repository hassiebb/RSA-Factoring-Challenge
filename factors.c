#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(int number) {
    int factor = 2;

    while (number > 1) {
        if (number % factor == 0) {
            printf("%d=%d*%d\n", number, factor, number / factor);
            number /= factor;
        } else {
            factor++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int number = atoi(line);
        factorize(number);
    }

    fclose(file);
    return 0;
}
