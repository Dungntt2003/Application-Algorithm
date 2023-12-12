#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

long A[MAX];
long n;
int L;

void ConvertToString(){
    for (int i = 0 ; i < n ; i++){
        string s = to_string(A[i]);
        int length = s.length();
        if ( length == L)
        {
            cout << s << endl;
            continue;
        }
        s = string(L - length, '0') + s;
        cout << s << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> L;
    for (int i = 0 ; i < n; i++){
        cin >> A[i];
    }
    ConvertToString();
    return 0;
}