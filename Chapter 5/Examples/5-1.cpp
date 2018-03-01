// Example 5-1 Where is the Marble?
// UVa 10474
// Language: C++

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int kase = 1;
    while(true){
        int marble_count, query_count;
        cin >> marble_count >> query_count;

        if(!marble_count && !query_count){
            break;
        }

        int *marbles = new int[marble_count];
        for(int i = 0;i < marble_count;i++){
            cin >> marbles[i];
        }
        sort(marbles, marbles + marble_count);

        cout << "CASE# " << kase << ":" << endl;

        while(query_count--){
            int query_num;
            cin >> query_num;

            int pos = 0;
            while(pos < marble_count){
                if(marbles[pos] >= query_num){
                    break;
                }
                pos++;
            }
            if(pos < marble_count && marbles[pos] == query_num){
                cout << query_num << " found at " << (pos + 1) << endl;
            }else{
                cout << query_num << " not found" << endl;
            }
        }

        delete[] marbles;
        kase++;
    }
    return 0;
}
