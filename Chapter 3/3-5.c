// Exercise 3-5 Digit Generator
// UVa 1583
// For more information, see problem 1583 on UVa Online Judge.

#include <stdio.h>

#define MAXN 100000+1
int ans[MAXN] = {0};

int main(void){
	for(int i = 0;i < MAXN;i++){
		int dsum = 0, temp = i;
		while(temp > 0){
			dsum += temp % 10;
			temp /= 10;
		}

		int sum = i + dsum;
		if(ans[sum] == 0 || i < ans[sum]){
			ans[sum] = i;
		}
	}

	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i++){
		int n;
		scanf("%d",&n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
