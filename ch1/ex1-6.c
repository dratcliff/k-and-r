#include <stdio.h>

// test (c = (getchar() != EOF)) is 0 or 1

main() {
    char c;
    while (c = (getchar() != EOF)) {
        printf("%d\n", c);
    }
    printf("%d\n", c);
}
