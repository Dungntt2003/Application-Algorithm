#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int A[N][N];
int n, m ;
int result = 0; 
string s;
unordered_set<string> Q;

string rowtoString(int k){
    string res = "";
    for (int i = 0 ; i < n ; i++){
        res += to_string(A[k][i]);
    }
    return s;
}

void input (){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> A[i][j];
        }
    }
}

void match(string a){
    for (const auto &b : Q){
        if (b.find(a)) result++;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    for (int i = 0 ; i < n ; i++){
        Q.insert(rowtoString(i));
    }
    cin >> m;
    while (m--){
        cin >> s;
        match(s);
    }
    cout << result << endl;
    return 0;
}