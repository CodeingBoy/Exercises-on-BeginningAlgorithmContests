// Exercise 1-7 Year
// Description: input a year, determine whether it is a leap year and say yes or no
// input:       a year
// output:      if it is a leap year, say "yes".
//              if it is not, say "no".
// language:    C(C99)

#include <stdio.h>

int main(void)
{
    int year;
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("yes");
    } else {
        printf("no");
    };
}