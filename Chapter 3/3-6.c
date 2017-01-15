// Exercise 3-6 Crossword Answers
// UVa 232
// For more information, see problem 232 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ShowAcrossWord(char** str, int** start, int r, int c){
    bool showing = false;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(!showing && start[i][j] != 0){
                printf("%3d.", start[i][j]);
                showing = true;
            }
            if(str[i][j] == '*'){
                if(showing){
                    putchar('\n');
                    showing = false;
                }
            }else{
                putchar(str[i][j]); 
            }
        } 
        if(showing){
            putchar('\n');
            showing = false;
        }
    }
} 

void ShowDownWord(char** str, int** start, int r, int c){
    bool showing = false;
    for(int k = 0;k < r;k++){
        for(int i = 0;i < c;i++){
            if(k > 0 && str[k-1][i] != '*')continue;
            for(int j = k;j < r;j++){
                if(!showing && start[j][i] != 0){
                    printf("%3d.", start[j][i]);
                    showing = true;
                }
                if(str[j][i] == '*'){
                    if(showing){
                        putchar('\n');
                        showing = false;
                    }
                    break;
                }else{
                    putchar(str[j][i]); 
                }
            } 
            if(showing){
                putchar('\n');
                showing = false;
            }
        }
    }
}

int main(void){
    int kase = 1;
    while(1){
        int r, c;
        scanf("%d", &r);
        if(r == 0)break;
        scanf("%d", &c);

        if(kase > 1)putchar('\n');

        char** matrix = (char**)malloc(r * sizeof(char*));
        for(int i = 0;i < r;i++){
            matrix[i] = (char*)malloc(c * sizeof(char));
            for(int j = 0;j < c;j++){
                char ch;
                while((ch = getchar()) == '\n');
                matrix[i][j] = ch;
            }
        }

        int** start = (int**)malloc(r * sizeof(int*));
        int cnt = 1;
        for(int i = 0;i < r;i++){
            start[i] = (int*)malloc(c * sizeof(int));
            for(int j = 0;j < c;j++){
                if(matrix[i][j] == '*'){
                    start[i][j] = 0;
                    continue;
                }
                if(i == 0){
                    start[i][j] = cnt;
                    cnt++;
                    continue; 
                }
                if(i < 1 || j < 1 || matrix[i][j-1] == '*' || matrix[i-1][j] == '*'){
                    start[i][j] = cnt;
                    cnt++;
                }else{
                    start[i][j] = 0;
                }
            }
        }

        printf("puzzle #%d:\n", kase);
        printf("Across\n");
        ShowAcrossWord(matrix, start, r, c);

        printf("Down\n");
        ShowDownWord(matrix, start, r, c);

        for(int i = 0;i < r;i++){
            free(start[i]);
            free(matrix[i]);
        }
        free(start);
        free(matrix);

        kase++;
    }
    return 0;
}
