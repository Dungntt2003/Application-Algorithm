#include <bits/stdc++.h>
using namespace std;
string str;
string key;
string value;
vector<string> word;

int checkFind(string value){
    sort(word.begin(), word.end());
    auto it = lower_bound(word.begin(), word.end(), value);
    if (it != word.end() && *it == value)
    return 1;
    return 0;
}

int checkInsert(string value){
    if (checkFind(value) == 0){
        word.push_back(value);
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    do {
        getline(cin , str);
        if (str != "*")
        word.push_back(str);
    }
    while (str != "*");

    do {
        getline(cin , str);
        if (str != "***"){
            stringstream ss(str);
            ss >> key >> value;
            if (key == "find"){
                cout << checkFind(value) << endl;
            }
            if (key == "insert"){
                cout << checkInsert(value) << endl;
            }
        }
    }
    while (str != "***");
    return 0;

}