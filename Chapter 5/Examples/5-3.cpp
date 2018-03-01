// Example 5-3 Andy's First Dictionary
// UVa 10815
// Language: C++

#include <iostream>
#include <set>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

string normalize_line(string &line){
    int pos = 0;
    for(int i = 0;i < line.size();i++){
        if(!isalpha(line[i])){
            line[i] = ' ';
        }
    }
    return line;
}

string normalize(const string &word){
    string result;
    for(int i = 0;i < word.size();i++){
        if(!isalpha(word[i])){
            continue;
        }
        result.append(1, tolower(word[i]));
    }
    return result;
}

int main(){
    set<string> dict;
    string line;
    while(!cin.eof()){
        getline(cin, line);
        stringstream ss;
        string word;
        line = normalize_line(line);
        ss << line;
        while(!ss.eof()){
            ss >> word;
            string normalized_word = normalize(word);
            if(normalized_word.empty()){
                continue;
            }
            dict.insert(normalized_word);
        }
    }
    for(auto it = dict.begin();it != dict.end();++it){
        cout << *it << endl;
    }

    return 0;
}
