// Example 5-4 Ananagrams
// UVa 156
// Language: C++ 11

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void to_lower(string &str){
    for(int i = 0;i < str.size();i++){
        str[i] = tolower(str[i]);
    }
}

string normalize(const string &word){
    string result = word;
    to_lower(result);
    sort(result.begin(), result.end());
    return result;
}

int main(){
    map<string, string> dict; 
    while(true){
        string word;
        cin >> word;
        if(word == "#"){
            break;
        }

        string key = normalize(word);
        if(dict.count(key)){
            dict[key] = "";
        }else{
            dict[key] = word;
        }
    }

    vector<string> results;
    for(auto it = dict.begin(); it != dict.end();++it){
        if(it->second != ""){
            /* cout << it->second << endl; */
            results.push_back(it->second);
        }
    }
    sort(results.begin(), results.end());

    for(auto it = results.begin(); it != results.end();++it){
        cout << *it << endl;
    }

    return 0;
}
