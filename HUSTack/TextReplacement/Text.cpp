#include <bits/stdc++.h>
using namespace std;
string s;
string a;
string b;

void solve(){
    size_t pos = 0;
    while ((pos = s.find(a, pos)) != string::npos){
        s.replace(pos, a.length(), b);
        pos += b.length();
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin ,a);
    getline(cin, b);
    getline(cin, s);
    solve();
    cout << s << endl;

    return 0;
}