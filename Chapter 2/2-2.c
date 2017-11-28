// Exercise 2-2 Hanxin
// Description: Hanxin is smart in checking how many soldiers he got. He just ask soldier queue up as three in a row, five in a row, seven in a row and get the number of soldiers in last row.
// Input: 3 integers which stands for the number of soldiers in last row
// Output: The total number of soldiers (or no answer), the total number is between 10 to 100.
// Example: Input: 2 1 6
//                 2 1 3
//         Output: Case 1: 41
//                 Case 2: No answer
// Language: C(C99)

#include <stdio.h>

int main(void)
{
	int kase=1;
	int a, b, c;
	while(scanf("%d %d %d",&a,&b,&c) == 3){
		// total % 3 == a, total % 5 == b, total % 7 == c
		// using Chinese remainder theorem to solve the problem
		// see https://en.wikipedia.org/wiki/Chinese_remainder_theorem for more information

		int total = a*70+b*21+c*15;
		total %= 105;

		printf("Case %d: ",kase);
		if(total > 100 || total < 10){ // no answer
			printf("No answer\n");
		}	
		else{
			printf("%d\n", total);
		}

		kase++;
	}
	return 0;
}
