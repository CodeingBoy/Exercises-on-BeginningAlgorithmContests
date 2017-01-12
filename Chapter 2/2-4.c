// Exercise 2-4 Subsequence
// Description: 
// Input: two integers n and m (n < m, both less than 10^6, may contain multiple input, n=0 and m=0 stands for ending)
// Output: (1/n^2)+(1+/(n+1)^2)+...+(1/m^2) (remain 5 digits after the decimal point)
// Example: Input: 2 4
//                 65536 655360
//                 0 0
//         Output: Case 1: 0.42361
//                 Case 2: 0.00001
// Language: C(C99)

#include <stdio.h>
#include <math.h>

int main(void){
	int n, m;
	while(scanf("%d %d",&n,&m)==2 && n > 0 && m > 0){
		double sum = 0;
		for(int i = n;i<=m;i++){
			sum+=1/pow(i,2);
		}  
		printf("%.5f\n",sum);
	}
	return 0;
}
