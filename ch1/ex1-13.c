#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20

// print histogram of word lengths

int main() {
    
    int c, state, characters_in_word;

    int length_counts[MAX_LENGTH] = { 0 };

    state = OUT;
    characters_in_word = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            
            if (characters_in_word) {
                length_counts[characters_in_word]++;
            }

            characters_in_word = 0;
        } else if (state == OUT) {
            state = IN;
        }
        if (state && characters_in_word < MAX_LENGTH - 1) {
            characters_in_word++;
        }
    }
    

    int max_occurrences = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (length_counts[i] > max_occurrences) {
            max_occurrences = length_counts[i];
        }
    }

    int occurrences_per_tick;
    if (max_occurrences < 50) {
        occurrences_per_tick = 1;
    } else if (max_occurrences < 500) {
        occurrences_per_tick = 10;
    } else if (max_occurrences < 5000) {
        occurrences_per_tick = 50;
    } else {
        occurrences_per_tick = 1000;
    }

    printf("length | occurrences |\n");
    for (int i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 1; i < MAX_LENGTH; i++) {
        if (i == MAX_LENGTH - 1) {
            printf("%6d+| %11d | ", i, length_counts[i]);
        } else {
            printf("%6d | %11d | ", i, length_counts[i]);
        }
        for (int j = 0; j < length_counts[i]; j++) {
            if (j % occurrences_per_tick == 0) {
                printf("-");
            }
        }
        printf("\n");
    }

}
