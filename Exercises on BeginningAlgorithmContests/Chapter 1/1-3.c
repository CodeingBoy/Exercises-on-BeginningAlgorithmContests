// Exercise 1-3 Sum
// Description: Calculate sum from 1 to n
// input:       integer n
// output:      the sum of 1+2+3+...+(n-2)+(n-1)+n
// language:    C(C99)

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // Gauss summation
    // 1+n = 2+(n-1) = 3+(n-2) = ...
    int sum = (1 + n) * (n / 2);

    if (n % 2 != 0) { // if n is odd
        sum += (1 + n / 2); // add center value
    }

    printf("%d", sum);
}
