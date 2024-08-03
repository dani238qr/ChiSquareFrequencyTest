#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BITS 100000

int main() {
    FILE *file = fopen("c_dataset.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    srand(time(NULL));

    for (int i = 0; i < NUM_BITS; ++i) {
        int bit = rand() % 2;
        fprintf(file, "%d", bit);
    }

    fclose(file);

    return 0;
}

