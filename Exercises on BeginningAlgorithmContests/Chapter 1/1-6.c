// Exercise 1-6 Triangle
// Description: input 3 integers and judge them if they can form a right-angled triangle
// input:       3 integers
// output:      if they can form a right-angled triangle, say "yes".
//              if can't, say "no".
//              if they can't form a triangle, say "not a triangle".
// language:    C(C99)

#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && abs(a - b) < c) { // is a triangle
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) { // is a right-angled triangle
            printf("yes");
        } else { // is NOT a right-angled triangle
            printf("no");
        }
    } else { // is NOT a triangle
        printf("not a triangle");
    }
}
