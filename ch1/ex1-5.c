#include <stdio.h>

// celsius to fahrenheit table, descending

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = upper;
    printf("%3s %6s\n", "c", "f");
    printf("%10s\n", "----------");
    while (celsius >= lower) {

        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius - step;
    }
}
