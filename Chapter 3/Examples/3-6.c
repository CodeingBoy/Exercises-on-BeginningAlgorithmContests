// Exercise 3-6 Circular Sequence
// UVa 1584
// For more information, see problem 1584 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int IsLexicographicallyLessThan(char str[], int offset1, int offset2){
	int len = strlen(str);
	int j = 0;
	for(;j < len;j++){
		if(str[(j+offset1)%len] != str[(j+offset2)%len]){
			return str[(j+offset1)%len] - str[(j+offset2)%len];
		}
	}
	return 0;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int kase = 0;kase < T;kase++){
		char seq[100+1];
		int ans = 0;
		scanf("%s",seq);
		int len = strlen(seq);

		for(int i = 1;i < len;i++){
			if(IsLexicographicallyLessThan(seq, ans, i) > 0){
				ans = i;
			}
		}

		for(int i = 0; i < len;i++){
			putchar(seq[(i+ans)%len]);
		}
		putchar('\n');
	}
	return 0;
}
