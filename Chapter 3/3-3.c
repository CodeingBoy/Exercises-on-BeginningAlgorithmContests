// Exercise 3-3 Palindrome
// UVa 401
// // For more information, see problem 401 on Uva Online Judge

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
	for(int i = 0;i < len/2 + 1;i++){
		int index = 0;
		while(index < strlen(original)){
			if (original[index] == str[i]){
				break;
			}
			index++;
		}
		if(str[len-1-i]!=mirrored[index]){
			return false;
		}
	}
	return true;
}
