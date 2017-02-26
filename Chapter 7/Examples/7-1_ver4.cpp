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
        int solve = 0;

        for(int f = 0;f < 10;f++){
            for(int g = 0;g < 10;g++){
                if(g == f)continue;
                for(int h = 0;h < 10;h++){
                    if(h == g)continue;
                    for(int i = 0;i < 10;i++){
                        if(i == h)continue;
                        for(int j = 0;j < 10;j++){
                            if(j == i)continue;
                            int num2 = f*10000+g*1000+h*100+i*10+j;    
                            int num1 = N * num2;
                            if(num1 >= 100000){
                                continue;
                            }
                            if(isUnique(num1, num2)){
                                cout << (num1 < 10000?"0":"") << num1 << " / " << (num2 < 10000?"0":"") << num2 << " = " << N << endl;
                                solve++;
                            }
                        }
                    }
                }
            }
        }

        if(solve == 0){
            cout << "There are no solutions for " << N << "." << endl;
        }
    }
}

bool isUnique(int num1, int num2){
    bool nums[10] = {false};

    if(num1 < 10000){
        nums[0]=true;
    }

    if(num2 < 10000){
        if(nums[0])return false;
        nums[0] = true;
    }

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
