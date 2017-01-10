// Exercise 1-5 Discount
// Description: The price of a clothes is 95 Yuan. You can get 15% off while paying more than 300 Yuan.
//              Input how many clothes you buy, output the amount you need to pay.
// input:       the num of clothes
// output:      the total price(remain 2 digits after the decimal point)
// language:    C(C99)

#include <stdio.h>

#define PRICE 95

int main(void)
{
    int clothesCount;
    scanf("%d", &clothesCount);

    double total = clothesCount * PRICE;

    if (total >= 300) {
        total *= 0.85;
    }

    printf("%.2f", total);
}
