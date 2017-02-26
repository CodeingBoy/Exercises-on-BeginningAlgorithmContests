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
            int result = 1;
            for(int j = i;j < N;j++){
                result *= nums[j];
                if(result > max){
                    max = result;
                }
            }
        }

        cout << "Case #" << kase << ":  The maximum product is " << max << "." << endl;
        cout << endl;

        delete[] nums;
        kase++;
    }
}
