// Example 7-4 Prime Ring Problem
// UVa 524
// For more information, see problem 524 on UVa Online Judge.
// Language: C++

#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNum(int num)
{
    int end = num / 2;
    for (int i = 2; i <= end; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isInNums(int num, int nums[], int size)
{
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] == num) {
            return false;
        }
    }
    return true;
}

void selectNextNum(int nums[], int pos, int n, int size)
{
    if (pos == size) {
        for (int i = 0; i < size; i++) {
            if (i) cout << " ";
            cout << nums[i];
        }
        cout << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (isInNums(i, nums, pos) && isPrimeNum(i + nums[pos - 1])) {
            nums[pos] = i;
            selectNextNum(nums, pos + 1, n, n);
        }
    }
}

int main()
{
    int n;
    int kase = 1;
    while (cin >> n) {
        int* nums = new int[n];
        nums[0] = 1;
        cout << "Case " << kase << ":" << endl;
        selectNextNum(nums, 1, n, n);

        delete[] nums;
        cout << endl;
        kase++;
    }
}
