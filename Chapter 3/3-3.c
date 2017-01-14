// Exercise 3-3 Digit Counting
// UVa 1225
// For more information, see problem 1225 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);

		int numCount[10] = {0};

		for(int i = 1;i <= n;i++){
			int temp = i;
			while(temp > 0){
				int digit = temp % 10;
				numCount[digit]++;
				temp /= 10;
			}
		}

		printf("%d", numCount[0]);
		for(int i = 1;i < 10;i++){
			printf(" %d", numCount[i]);
		}
		putchar('\n');
	}
	return 0;
}
