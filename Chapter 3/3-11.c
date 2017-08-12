// 3-11 Kickdown
// UVa 1588
// For more information, see problem 1588 on UVa online judge.
// Language: C99

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

int test(char master[], char driven[]){
    int len_master = strlen(master), len_driven = strlen(driven);

#ifdef DEBUG
    puts(master);
    puts(driven);
#endif

    int len = len_master <= len_driven ? len_master : len_driven;
    for(int i = 0;i < len;i++){
        int a = master[i] - '0', b = driven[i] - '0';
        if(a + b > 3){
#ifdef DEBUG
            printf("Illegal\n\n");
#endif
            return -1;
        }
#ifdef DEBUG
        printf("%d", a+b);
#endif
    }
#ifdef DEBUG
    printf("\n");
    printf("%d\n\n", len_master > len_driven ? len_master : len_driven);
#endif
    return len_master > len_driven ? len_master : len_driven;
}

int main(void){
    while(true){
        char master[SIZE + 5], driven[SIZE + 5];

        if(scanf("%s %s", master, driven) < 2){
            break;
        }

        // get rid of \n
        //master[strlen(master) - 1] = 0;
        //driven[strlen(driven) - 1] = 0;

        int min = strlen(master) + strlen(driven);
#ifdef SHOWDETAIL
        int min1;
#endif
        for(int i = 0;i < strlen(driven);i++){
            char buffer[SIZE * 2];
            memset(buffer, '0', sizeof(char) * SIZE * 2);
            buffer[SIZE * 2 - 1] = 0;

            int result;
            strcpy(buffer+i, master);
            result = test(buffer, driven);

            if(result != -1){
                min = result < min ? result : min;
            }
        }
#ifdef SHOWDETAIL
        min1 = min;
#endif
        for(int i = 0;i < strlen(master);i++){
            char buffer[SIZE * 2];
            memset(buffer, '0', sizeof(char) * SIZE * 2);
            buffer[SIZE * 2 - 1] = 0;

            int result;
            strcpy(buffer+i, driven);
            result = test(master, buffer);

            if(result != -1){
                min = result < min ? result : min;
            }
        }

        printf("%d\n", min);
#ifdef SHOWDETAIL
        printf("%d\n", min1);
#endif

    }

    return 0;
}

