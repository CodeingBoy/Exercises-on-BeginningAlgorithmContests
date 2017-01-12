// Exercise 2-6 Permutation
// Description: Use 1 to 9 to form 3 three digits number: abc, def and ghi. Each number should be used at least once and only once. abc:def:ghi = 1:2:3.
// Input: Nothing
// Output: abc def ghi, each answer should fill a sperate line
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>

bool HaveDumplicateDigits(int num1,int num2, int num3);

int main(void){
	for(int i = 1;i<=3;i++){
		for(int j = 1;j<=9;j++){
			if(j == i){
				continue;
			}
			for(int k = 1;k<=9;k++){
				if(k == j || k == i){
					continue;
				}
				int num1 = i*100+j*10+k;
				int num2 = num1 *2;
				int num3 = num1 *3;
				if(num2<1000 && num3<1000){
					if(HaveDumplicateDigits(num1,num2,num3))
						printf("%d %d %d\n", num1,num2,num3);
				}
			}
		}
	}
	return 0;
}

bool HaveDumplicateDigits(int num1,int num2, int num3){
	int a = num1 / 100, b = num1 /10 % 10, c = num1 % 10;
	bool used[10] = {false};
	used[a]=true;
	used[b]=true;
	used[c]=true;

	int d = num2 / 100, e = num2 / 10 % 10, f = num2 % 10;
	if(used[d])return false;
	used[d]=true;
	if(used[e])return false;
	used[e]=true;
	if(used[f])return false;
	used[f]=true;

	int h = num3 / 100, i = num3 / 10 % 10, k = num3 % 10;
	if(used[h])return false;
	used[h]=true;
	if(used[i])return false;
	used[i]=true;
	if(used[k])return false;
	used[k]=true;

	if(used[0])return false;
	return true;
}

