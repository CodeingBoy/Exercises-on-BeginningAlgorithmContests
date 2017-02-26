// Example 7-2 Maximum Product
// UVa 11059
// For more information, see problem 11059 on UVa Online Judge.
// Language: C++

#include <iostream>

using namespace std;

int main(){
    int N;
    int kase = 1;
    while(cin >> N){
        int* nums = new int[N];
        for(int i = 0;i < N;i++){
            cin >> nums[i];
        }

        int max = 0;
        for(int i = 0;i < N;i++){
            int result = nums[i];
            for(int j = i + 1;j < N;j++){
                result *= nums[j];
                if(result > max){
                    max = result;
                }
            }
        }

        if(max < 0){
            max = 0;
        }

        cout << "Case #" << kase << ":  The maximum product is " << max << "." << endl;

        delete[] nums;
        kase++;
    }
}
