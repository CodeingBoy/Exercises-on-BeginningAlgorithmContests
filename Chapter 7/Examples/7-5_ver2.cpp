// Example 7-5 Krypton Factor
// UVa 129
// For more informaion, see problem 129 on UVa Online Judge
// Language: C++

#include <iostream>

using namespace std;

int solution = 0;
int n, L;

void printStr(int str[], int size)
{
    solution++;
    //if (solution == n) {
    for (int i = 0; i < size ; i++) {
        if (str[i] == -1)return;
        if (i && i % 4 == 0) cout << " ";
        cout << (char)('A' + str[i]);
    }
    cout << endl;
    cout << size << endl;
    //}
}

void selectNextCharacter(int str[], int pos, int L)
{
    if (pos)printStr(str, pos);
    if (solution >= n) {
        return;
    }

    for (int i = 0; i < L; i++) {
        if (pos && str[pos - 1] == i) continue;
        str[pos] = i;

        bool haveRepeat = false;
        for (int i1 = 1; i1 * 2 < pos + 1; ++i1) {
            bool isEqual = false;
            for (int j = 0; j < i1; ++j) {
                if (str[pos - j] == str[pos - i1 - j]) {
                    isEqual = true;
                    break;
                }
            }
            if (isEqual) {
                haveRepeat = true;
                break;
            }
        }
        if (!haveRepeat) {
            selectNextCharacter(str, pos + 1, L);
        }
    }
    str[pos] = -1;
}

int main()
{
    while (cin >> n >> L && n != 0 && L != 0) {
        solution = 0;
        int str[80] = {-1};
        selectNextCharacter(str, 0, L);
    }
}
