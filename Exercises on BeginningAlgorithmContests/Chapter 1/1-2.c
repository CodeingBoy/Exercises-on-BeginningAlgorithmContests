// Exercise 1-2 Temperature
// input: degree fahrenheit
// output: degree centigrade(remain 3 digits after the decimal point)
// language: C(C99)

#include <stdio.h>

int main(void)
{
    // get degree fahrenheit
    double fahrenheit;
    scanf("%lf", &fahrenheit);

    // convert degree fahrenheit to degree centigrade
    // by using formula c=5(f-32)/9

    double centigrade = 5 * (fahrenheit - 32) / 9;

    printf("%.3f", centigrade);

    getchar();
    getchar();
}
