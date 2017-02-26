// Example 7-1 Division
// UVa 725
// For more information, see problem 725 on UVa Online Judge.
// Language: C++

#include <iostream>

using namespace std;

bool isUnique(int, int);

int main(){
    int input;
    while(cin >> input && input){
        const int N = input;

        for(int f = 0;f < 10;f++){
            for(int g = 0;g < 10;g++){
                for(int h = 0;h < 10;h++){
                    for(int i = 0;i < 10;i++){
                        for(int j = 0;j < 10;j++){
                            int num2 = f*10000+g*1000+h*100+i*10+j;    
                            int num1 = N * num2;
                            if(isUnique(num1, num2)){
                                cout << num1 << " / " << num2 << " = " << N << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

bool isUnique(int num1, int num2){
    bool nums[10] = {false};

    while(num1){
        int digit = num1 % 10;
        if(nums[digit]){
            return false;
        }else{
            nums[digit] = true;
        }
        num1 /= 10;
    }

    while(num2){
        int digit = num2 % 10;
        if(nums[digit]){
            return false;
        }else{
            nums[digit] = true;
        }
        num2 /= 10;
    }

    return true;
}
