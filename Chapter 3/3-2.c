// Exercise 3-2 Molar mass
// UVa 1586
// For more information, see problem 1586 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <ctype.h>

int main(void){
	int T;
	scanf("%d\n",&T);
	while(T--){
		double molarMass = 0;
		char chemicalSym;

		while((chemicalSym = getchar()) != '\n'){
			int quantity = 1;

			char nextSym = getchar();
			ungetc(nextSym, stdin);
			if(isdigit(nextSym)){
				scanf("%d", &quantity);
			}

			double standardAtomicWeight = 0;
			switch(chemicalSym){
				case 'C':standardAtomicWeight = 12.01;
					 break;
				case 'H':standardAtomicWeight = 1.008;
					 break;
				case 'O':standardAtomicWeight = 16.00;
					 break;
				case 'N':standardAtomicWeight = 14.01;
					 break;
				default: break; // do nothing
			}

			molarMass += standardAtomicWeight * quantity;	

		}
		printf("%.3f\n", molarMass);
	}
	return 0;
}
