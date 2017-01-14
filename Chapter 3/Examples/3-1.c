// Exercise 3-1 TEX Quotes
// UVa 272
// For more information, see problem 272 on Uva Online Judge
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void){
	char result[1024];

	bool openQuote = false;
	char c;
	int j=0;
	while((c = getchar()) != EOF){
		if(c=='\n'){
			printf("%s\n",result);
			j = 0;
			memset(result,0,1024*sizeof(char));
			continue;
		}
		if(c == '"'){
			if(!openQuote){
				result[j] = '`';
				result[j+1] = '`';
				openQuote = true;
				j+=2;
			}else{
				result[j] = '\'';
				result[j+1] = '\'';
				openQuote = false;
				j+=2;
			}
			continue;
		}else{
			result[j] = c;
			j++;
		}
	}
	return 0;

}
