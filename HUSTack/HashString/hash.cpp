#include <bits/stdc++.h>
using namespace std;
string str;
int n, m;

long long int Hash(string s){
    long long int res = 0;
    int k = s.length();
    for (int i = 0 ; i < s.length() ; i++){
        res += s[i] * pow(256, k-1);
        k--;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (n--){
        cin >> str;
        cout << Hash(str)%m << endl;
    }
    return 0;
}