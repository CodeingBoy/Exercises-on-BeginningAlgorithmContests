// Exercise 3-8 Repeating Decimals
// UVa 202
// For more information, see problem 202 on UVa Online Judge.
// Language: C(C99)


#include <stdio.h>
#include <stdbool.h>

#define BIGSIZE (3000 + 10)

int HaveSeenRemain(int seen_remain[], int quotients[], int size, int remain, int quotient){
    for(int i = 0;i < size;i++){
        if(seen_remain[i] == remain && quotients[i] == quotient){
            return i;
        }
    } 
    return -1;
}

int CalcRepeation(int num1, int num2, int quotients[BIGSIZE], int* qlen){
    int remain = num1 % num2;
    int seen_remain[BIGSIZE] = {-1}; 
    // int quotients[BIGSIZE] = {-1};
    int pos = 0;
    int repeatPos;

    while(true){
        num1 = remain;
        num1 *= 10;
        quotients[pos] = num1 / num2;
        seen_remain[pos] = num1 % num2;
        repeatPos = HaveSeenRemain(seen_remain, quotients, pos, seen_remain[pos], quotients[pos]);
        if(repeatPos != -1){
            *qlen = pos;
            return repeatPos;
        }

        remain = seen_remain[pos];
        pos++;
    }
}

int main(void){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        int quotients[BIGSIZE] = {-1};
        int qlen;
        int repeatStartPos = CalcRepeation(n, m, quotients, &qlen);

        printf("%d/%d = %d.", n, m, n/m);
        for(int i = 0; i < repeatStartPos;i++){
            printf("%d",quotients[i]);
        } 
        putchar('(');
        for(int i = repeatStartPos;i < qlen;i++){
            printf("%d",quotients[i]);
            if(i - repeatStartPos >= 50 - 1){
                printf("...");
                break;
            }
        }
        putchar(')');
        putchar('\n');
        printf("   %d = number of digits in repeating cycle\n\n", qlen - repeatStartPos);

    }
}
