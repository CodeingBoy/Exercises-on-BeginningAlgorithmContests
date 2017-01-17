// Exercise 3-9 All in All
// UVa 10340
// For more information, see problem 10340 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100000

char s[SIZE], t[SIZE]; 

int main(void){
    while(true){
        memset(s, 0, SIZE * sizeof(char));
        memset(t, 0, SIZE * sizeof(char));
        // to detect EOF by using scanf, compare return value and EOF
        if(scanf("%s", s) == EOF || scanf("%s", t) == EOF){
            break;
        }

        int len_s = strlen(s);

        bool no = false;
        char* pos_prev = t;
        for(int i = 0;i < len_s;i++){
            char* pos = strchr(pos_prev, s[i]);
            if(pos == NULL){
                no = true;
                break;
            } 
            pos_prev = pos+1;
        } 

        if(no){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}
