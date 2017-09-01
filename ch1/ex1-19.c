#include <stdio.h>

#define MAXLENGTH 1000

void reverse(char string[], int len);
int getLine(char line[], int max);

// reverse input one line at a time

int main() {
    int len;
    char line[MAXLENGTH];

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
}

void reverse(char string[], int len) {
    char temp[len];
    int i;
    for (i = 0; i < len; i++) {
        temp[i] = string[i];
    }
    temp[len] = '\0';

    for (i = 0; i < len; i++) {
        string[i] = temp[len-i-1];
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
