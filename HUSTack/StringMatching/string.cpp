#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int StringMatch (string s1, string s2){
    int num = 0;
    size_t pos = 0;
    while ((pos = s1.find(s2, pos)) != string::npos){
        num++;
        pos += s2.length();
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin, s1);
    getline(cin , s2);
    cout << StringMatch(s2, s1) << endl;
    return 0;
}