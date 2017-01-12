// Exercise 2-5 Decimal
// Input: 3 integers a, b, c (may contain multiple input, end when a = b = c = 0)
// Output: a/b (remain c digits after the decimal point)
// Example: Input: 1 6 4
//                 0 0 0
//         Output: Case 1: 0.1667
// Language: C(C99)

#include <stdio.h>

int main(void){
	int kase = 1;
	int a,b,c;
	while(scanf("%d %d %d", &a, &b, &c) == 3
			&& !(a==0 && b==0 && c==0)){
		double decimal = (double)a/b;
		printf("Case %d: %.*f\n",kase,c,decimal);
		kase++;
	}
	return 0;
}
