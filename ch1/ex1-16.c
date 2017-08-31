#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline); // should've been getline, but stdio has its own now
void copy(char to[], char from[]);

/* print longest input line (arbitrary length) 
 * 
 * as far as I can tell, the intent of this exercise
 * is for the reader to only modify the main function
 * and to keep some "hard" limit on the size of the
 * character array to be printed.
 *
 */

int main() {
    int c;
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        // begin modification
        if (line[len-1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                len++;
            }
            if (c == '\n') {
                len++;
            }
        }
        // end modification
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        // begin modification
        printf("The longest line of input was %d characters long.\n", max);
        printf("The first %d characters of the longest line are:\n", MAXLINE);
        printf("%s\n", longest);
        // end modification
    }

    return 0;
}

int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
