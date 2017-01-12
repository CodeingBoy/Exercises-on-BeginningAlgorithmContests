// Exercise 2-1 Daffodil
// Description: Calculate daffodil number between 100 to 999. The definition of daffodil number is, ABC=A^3+B^3+C^3, for example, 153 equals to 1^3+5^3+3^3, which is a daffidil number.
// Input: Nothing
// Output: Daffodil numbers between 100 to 999
// Language: C(C99)

#include <stdio.h>
#include <math.h>

#define DIGITCOUNT 3

void GetDigits(int, int[]);

int main(void)
{
	for(int i = 100;i < 1000;i++){
		int digits[DIGITCOUNT];
		GetDigits(i, digits);

		int sum = 0;
		for(int j = 0;j<DIGITCOUNT;j++){
			sum+=pow(digits[j],3);
		}
		if(sum == i){
			printf("%d\n",i);
		}
	}
	return 0;
}

void GetDigits(int num, int digits[])
{
	int i = 0;
	while(num % 10 != 0)
	{
		digits[DIGITCOUNT-1-i]=num%10;
		num/=10; 
		i++;
	}
}
