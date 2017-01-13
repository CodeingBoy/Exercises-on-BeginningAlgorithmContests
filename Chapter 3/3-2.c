// Exercise 3-2 WERTYU
// UVa 10082
// For more information, see problem 10082 on Uva Online Judge

#include <stdio.h>
#include <string.h>

char keys[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(void){
	char c;
	while((c = getchar()) != EOF){
		char* index = strchr(keys, c);
		if (index == NULL){
			putchar(c);
			continue;
		}else{
			putchar(*(index - 1));
		}
	} 
	return 0;
}
