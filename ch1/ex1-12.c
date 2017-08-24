#include <stdio.h>

#define IN  1
#define OUT 0

// print one word per line

main() {
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c =='\t') {
            if (state) {
                putchar('\n');
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
        }
        if (state) {
            putchar(c);
        }
    }
}
