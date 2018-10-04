#include <stdio.h>

float convert_to_fahr(float celcius) {
    return (celcius * (9.0/5.0) + 32);
}

int main()
{
    printf("Celcius-to-Fahrenheit:\n");
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;
    while(celcius <= upper) {
        fahr = convert_to_fahr(celcius);
        printf("%3.0f %6.1f\n", celcius, fahr);
        celcius += step;
    }
}
