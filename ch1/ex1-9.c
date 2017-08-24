#include <stdio.h>

// collapse multiple spaces to one

main() {
    int c;
    int in_space = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (in_space) {
                continue;
            } else {
                in_space = 1;
            }
        } else if (c != ' ' && in_space){
            in_space = 0;
        }
        putchar(c);
    }
}
