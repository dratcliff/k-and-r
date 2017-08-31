#include <stdio.h>
#define MAXLENGTH 1000

// print all lines longer than 80 characters

int getLine(char line[], int max);
int trim(char line[], int len);

int main() {
    int c;
    int len;
    int trimlen;
    char line[MAXLENGTH];

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        if ((trimlen = trim(line, len)) > 1) {
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

int trim(char line[], int len) {
    int c;
    for (c = line[len-1]; c == ' ' || c == '\t' || c == '\n' && len > 0; c = line[--len-1]) {
        line[len-1] = '\n';
        line[len] = '\0';
    }
    return len;
}
