// Exercise 3-3 Palindrome
// UVa 401
// For more information, see problem 401 on Uva Online Judge
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool IsPalindromeString(char str[]);
bool IsMirroredString(char str[]);

char original[] = "AEHIJLMOSTUVWXYZ12358";
char mirrored[] = "A3HILJMO2TUVWXY51SEZ8";

int main(void){
	char buffer[2048];
	while(fgets(buffer,2048,stdin) != NULL){
		buffer[strlen(buffer)-1] = 0; // replace \n

		bool isPalindrome = IsPalindromeString(buffer);
		bool isMirrored = IsMirroredString(buffer);
		printf("%s", buffer);
		if(!isPalindrome && !isMirrored){
			printf(" -- is not a palindrome.\n");
		}else if(isPalindrome && !isMirrored){
			printf(" -- is a regular palindrome.\n");
		}else if(!isPalindrome && isMirrored){
			printf(" -- is a mirrored string.\n");
		}else{
			printf(" -- is a mirrored palindrome.\n");
		}
		printf("\n");
	}
	return 0;
}

bool IsPalindromeString(char str[]){
	int len = strlen(str);
	for(int i = 0;i < len/2;i++){
		if(str[i]!=str[len-1-i]){
			return false;
		}
	}
	return true;
}

bool IsMirroredString(char str[]){
	int len = strlen(str);
    // wondering why loop needs iterate (len/2)+1 times?
    // because the middle character needs to be a mirror character(e.g. M O Y)
    // if middle character is not a mirror character, like N B, we need to refuse it
    // the purpose of +1 is detect the middle character is whether mirror character or not
	for(int i = 0;i < len/2 + 1;i++){
		int index = 0;
        // search for mirror character
		while(index < strlen(original)){
			if (original[index] == str[i]){
				break;
			}
			index++;
		}
        // seems I did not handle character is not exist in mirror character table
        if(index >= strlen(original)){
            return false;
        }

        // detect if they are not same
		if(str[len-1-i]!=mirrored[index]){
			return false;
		}
	}
	return true;
}
