// Exercise 3-7 DNA Consensus String
// UVa 1368
// For more information, see problem 1368 on UVa Online Judge.
// Language: C(C99)

#include <stdio.h>
#include <stdlib.h>

char GetHammingDisMinChar(char** str, int size, int pos){
    int chCount[4] = {0};
    for(int i = 0;i < size;i++){
        switch(str[i][pos]){
            case 'A':chCount[0]++;
                     break;
            case 'C':chCount[1]++;
                     break;
            case 'G':chCount[2]++;
                     break;
            case 'T':chCount[3]++;
                     break;
        }
    }

    int maxIndex = 0;
    for(int i = 1;i < 4;i++){
        if(chCount[i] > chCount[maxIndex]){
            maxIndex = i;
        }
    }

    switch(maxIndex){
        case 0:return 'A';
        case 1:return 'C';
        case 2:return 'G';
        case 3:return 'T';
    }
    return -1;
}

int CalcHammingDis_Str(char a[], char b[]){
    int i = 0;
    int diff = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i]){
            diff++;
        }
        i++;
    }
    return diff;
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int m, n;
        scanf("%d %d", &m, &n);

        char** seqs = (char**)malloc(m * sizeof(char**));
        for(int i = 0;i < m;i++){
            seqs[i] = (char*)malloc((n+1) * sizeof(char));
            scanf("%s", seqs[i]);
        }

        char* result = (char*)malloc((n+1) * sizeof(char));
        for(int i = 0;i < n;i++){
            char minChar = GetHammingDisMinChar(seqs, m, i);
            result[i] = minChar; 
        }
        result[n] = 0;

        printf("%s\n", result);
        int sum_dis = 0;
        for(int i = 0;i < m;i++){
            sum_dis += CalcHammingDis_Str(result, seqs[i]); 
        }
        printf("%d\n", sum_dis);

        free(result);
        for(int i = 0;i < m;i++){
            free(seqs[i]);
        }
        free(seqs);
    }
    return 0;
}
