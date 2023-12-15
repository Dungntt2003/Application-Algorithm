#include <bits/stdc++.h>
using namespace std;
string str;
string key;
string value;
unordered_set <string> Word;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    do {
        getline(cin , str);
        if (str != "*")
        Word.insert(str);
    }
    while (str != "*");

    do {
        getline(cin , str);
        if (str != "***"){
            stringstream ss(str);
            ss >> key >> value;
            if (key == "find"){
                if (Word.find(value) != Word.end())
                cout << 1  << endl;
                else cout << 0 << endl;
            }
            if (key == "insert"){
                auto check = Word.insert(value);
                if (check.second) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }
    while (str != "***");
    return 0;

}