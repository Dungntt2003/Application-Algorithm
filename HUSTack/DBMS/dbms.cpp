#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m , L;
set<string> D;
set<int> B;

string ConvertToString(int k){
        string s = to_string(k);
        int length = s.length();
        if ( length == L)
        {
            return s;
        }
        s = string(L - length, '0') + s;
        return s;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> L >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> s;
        D.insert(s);
        B.insert(stoi(s));
    }
    auto it = B.begin();
    auto prev = it++;
    if (*prev > 1){
            for (int i = 1 ; i < *prev ; i++){
                D.insert(ConvertToString(i));
            }
    }
    while (it != B.end()) {
        // cout << *prev << " " << *it << endl;
        for (int i = *prev + 1; i < *it ; i++){
            D.insert(ConvertToString(i));
        }
        prev = it++;
    }
    if (*prev < m + n ) {
        for (int i = *prev + 1 ; i <= m + n ; i++){
            D.insert(ConvertToString(i));
        }
    }
    for (const auto &a : D){
        cout << a << endl;
    }
    return 0;
}