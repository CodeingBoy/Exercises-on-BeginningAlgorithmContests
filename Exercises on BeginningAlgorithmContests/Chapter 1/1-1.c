// Exercise 1-1 Average
// input: 3 integers
// ouput: the average value of 3 integers, remain 3 digits after the decimal point
// language: C(C99)

#define NUMCOUNT 3
#include <stdio.h>

int main(void)
{
    // ask user to input numbers
    int nums[NUMCOUNT];
    int total = 0;
    for (int i = 0; i < NUMCOUNT; i++) {
        //printf("Please input number %d: ", i + 1);
        scanf("%d", &nums[i]);
        total += nums[i];
    }

    // calculate average value
    double average = (double)total / NUMCOUNT;

    // print result
    //printf("Average: %.3f", average);
    printf("%.3f", average);
}