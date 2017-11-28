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
        int got_answer = 0;

		printf("Case %d: ",kase);
        for(int i = 2;i < 15;i++){
            int possible_count = 7 * i + c;
            if(possible_count % 3 == a && possible_count % 5 == b){
                printf("%d\n", possible_count);
                got_answer = 1;
                break;
            }
        }
        if(!got_answer){
            printf("No answer\n");
        }

		kase++;
	}
	return 0;
}
