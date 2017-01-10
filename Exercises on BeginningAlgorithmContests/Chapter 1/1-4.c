// Exercise 1-4 Sin and Cos
// Description: Calculate sine and cosine value of degree n
// input:       degree n (n>=0 && n<360)
// output:      sine and cosine value of degree n
// language:    C(C99)

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main(void)
{
    int degree;
    scanf("%d", &degree);

    // function sin() and cos require radian, so we need convert degree to radian
    // deg = (180 / PI) * degree
    double radian = PI * degree / 180 ;

    printf("%f %f", sin(radian), cos(radian));
}
