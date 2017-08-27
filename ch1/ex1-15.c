#include <stdio.h>

float fahrToCelsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

// fahrenheit to celsius table with a function
int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %6s\n", "f", "c");
    printf("%10s\n", "----------");
    while (fahr <= upper) {
        celsius = fahrToCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}
