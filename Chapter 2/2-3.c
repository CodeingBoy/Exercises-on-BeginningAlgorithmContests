// Exercise 2-3 Triangle
// Description: Print a n row inverted triangle
// Input: integer n
// Output: a n row inverted triangle
// Language: C(C99)

#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	int width = 2*(n-1)+1;
	for(int i = 0;i<n;i++){
		// n = 1, #
		// n = 2, ###, 1+2(n-1)=2n-1
		int hashCount = 2*(n-1-i)+1; // inverted
		int spaceCount = width - hashCount; 
		int charCount = 0;
		while(charCount<spaceCount/2){
			putchar(' '); 
			charCount++;
		}
		while(hashCount){
			putchar('#');
			hashCount--; 
			charCount++;
		}
		while(charCount < width){
			putchar(' ');
			charCount++;
		}
		putchar('\n');
	}
	return 0;
}
