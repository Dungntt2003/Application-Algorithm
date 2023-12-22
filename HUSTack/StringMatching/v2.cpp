#include<bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    string fn;
    cin >> fn;
    cin.ignore(); // Ignore the newline character after reading fn

    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    map<string, int> mp;

    while (ss >> word) {
        mp[word]++;
    }
    for (const auto &a : mp){
        if (a.first.find(fn) != string::npos){
            res += a.second;
        }
    }

    cout << res;
    return 0;
}
