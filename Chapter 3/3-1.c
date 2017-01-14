// Exercise 3-1 Score
// UVa 1585
// For more information, see problem 1585 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>

int main(void){
	int T;
	scanf("%d\n", &T);
	while(T--){
		int score = 0;
		int combo = 0;

		char c;
		while((c = getchar()) != '\n'){
			if(c == 'O'){
				combo++;
				score += combo;
			}else{
				combo = 0;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
