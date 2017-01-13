// Exercise 3-4 Master-Mind Hints
// UVa 340
// For more information, see problem 340 on UVa Online Judge

#include <stdio.h>
#include <stdbool.h>

int main(void){
	int gameCount = 1;
	int N;
	while(scanf("%d",&N) && N >0){
		int code[1000] = {-1};
		for(int i = 0;i < N;i++){
			scanf("%d",&code[i]);
		}

		printf("Game %d:\n",gameCount);
		// get guess
		while(true){
			int guess[1000]={-1};
			for(int i = 0;i < N;i++){
				scanf("%d",&guess[i]);
			}

			if(guess[0] == 0)break;

			// get strong count
			int totalStrongCount = 0;
			int strongCount[1000] = {0};
			for(int i = 0;i < N;i++){
				if(code[i] == guess[i]){
					strongCount[i]++;
				}
				totalStrongCount+=strongCount[i];
			}

			// get weak count
			int totalWeakCount = 0;
			int weak[1000] = {0};
			for(int i = 0;i < N;i++){
				if(strongCount[i])continue;
				for(int j = 0;j < N;j++){
					if(strongCount[j])continue;
					if(guess[i] == code[j] && !weak[j]){
						weak[j]=1;
						totalWeakCount++;
						break;
					}
				}
			}

			// print hint
			printf("    (%d,%d)\n",totalStrongCount,totalWeakCount);
		}
		gameCount++;
	}
	return 0;
}
