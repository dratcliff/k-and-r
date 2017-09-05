#include <stdio.h>

#define TABSTOP 8
#define MAXLENGTH 1000

int getLine(char line[], int max);
void detab(char line[], int len);
int nxtabstp(int pos);

/*
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every *n* columns. Should *n* be a variable or a symbolic parameter?
 */

int main() {
    int len = 0;
    char line[MAXLENGTH];

    while ((len = getLine(line, MAXLENGTH)) > 0) {
        detab(line, len);
    }
}

void detab(char line[], int len) {
    int i, j, next, pos;
    pos = 0;
    for (i = 0; i < len; i++) {
        if (line[i] == '\t') {
            next = nxtabstp(pos); 
            for (j = pos; j < next; j++) {
                printf(" ");
                pos++;
            };
        } else {
            printf("%c", line[i]);
            pos++;
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

int nxtabstp(int pos) {
    int i;
    for (i = 0; i < MAXLENGTH; i = i + TABSTOP) {
        if (i > pos) {
            return i;
        }
    }
    return 0;
}
