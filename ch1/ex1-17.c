#include <stdio.h>
#define MAXLENGTH 1000

// print all lines longer than 80 characters

int getLine(char line[], int max);

int main() {
    int c;
    int len;
    char line[MAXLENGTH];

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }
}

int getLine(char line[], int max) {
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
