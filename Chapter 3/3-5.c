// Exercise 3-5 Puzzle
// UVa 227
// For more information, see problem 227 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>

void Swap(char* a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

bool Operate(char puzzle[][5], int blank_x, int blank_y){
	char oper;
	while((oper = getchar()) != '0'){
		switch(oper){
			case 'A':if(blank_x < 1)return false;
					 Swap(&puzzle[blank_x][blank_y], &puzzle[blank_x-1][blank_y]);
				 blank_x--;
				 break;
			case 'B':if(blank_x > 3)return false;
					 Swap(&puzzle[blank_x][blank_y], &puzzle[blank_x+1][blank_y]);
				 blank_x++;
				 break;
			case 'R':if(blank_y > 3)return false;
					 Swap(&puzzle[blank_x][blank_y], &puzzle[blank_x][blank_y+1]);
				 blank_y++;
				 break;
			case 'L':if(blank_y < 1)return false;
					 Swap(&puzzle[blank_x][blank_y], &puzzle[blank_x][blank_y-1]);
				 blank_y--;
				 break;
		}
	}
	return true;
}

int main(void){
	int kase = 1;
	while(true){
		char puzzle[5][5];
		int blank_x, blank_y;
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				char c;
				while((c = getchar()) == '\n');
				if(c == 'Z'){
					return 0;	
				}

				puzzle[i][j] = c;
				if(puzzle[i][j] == ' '){
					blank_x = i;
					blank_y = j;
				}
			}
		}
		if(kase > 1)putchar('\n');
		printf("Puzzle #%d:\n", kase);
		if(Operate(puzzle, blank_x, blank_y)){
			for(int i = 0;i<5;i++){
				printf("%c %c %c %c %c\n", puzzle[i][0], puzzle[i][1], puzzle[i][2], puzzle[i][3]
						, puzzle[i][4]);
			}
		}else{
			while(getchar()!='0');
			printf("This puzzle has no final configuration.\n");
		}
		kase++;
	}
	return 0;
}
