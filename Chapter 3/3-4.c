// Exercise 3-4 Periodic Strings
// UVa 455
// For more information, see problem 455 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool IsOffsetValid(char input[], int offset){
	int len = strlen(input);
	for(int i = 0;i < len;i++){
		if(input[i % len] != input[(i + offset) % len]){
			return false;
		}
	}
	return true;
}

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		char input[100];
		scanf("%s", input);

		int offset = 1;
		int len = strlen(input);
		while(offset < len){
			if(IsOffsetValid(input, offset)){
				break;
			}
			offset++;
		}

		printf("%d\n", offset);
		if(N > 0){
			printf("\n");
		} 
	}
	return 0;
}
