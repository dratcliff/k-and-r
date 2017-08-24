#include <stdio.h>

#define IN 1
#define OUT 0

// print histogram of character frequencies

int main() {
    
    int c, state;

    int frequencies[128] = { 0 };

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c < 128) {
            frequencies[c]++;
        }
    }
    

    int max_occurrences = 0;
    for (int i = 0; i < 128; i++) {
        if (frequencies[i] > max_occurrences) {
            max_occurrences = frequencies[i];
        }
    }

    int occurrences_per_tick;
    if (max_occurrences < 50) {
        occurrences_per_tick = 1;
    } else if (max_occurrences < 500) {
        occurrences_per_tick = 10;
    } else if (max_occurrences < 5000) {
        occurrences_per_tick = 50;
    } else if (max_occurrences < 50000) {
        occurrences_per_tick = 1000;
    } else {
        occurrences_per_tick = 10000;
    }

    printf("char   | occurrences |\n");
    for (int i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = ' '; i <= '~'; i++) {
        printf("%6c | %11d | ", i, frequencies[i]);
        for (int j = 0; j < frequencies[i]; j++) {
            if (j % occurrences_per_tick == 0) {
                printf("-");
            }
        }
        printf("\n");
    }

}
