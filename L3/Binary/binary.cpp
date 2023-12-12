#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int A[N];

void solve(){
    for (int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


void Try(int k){
    for (int i = 0 ; i <= 1 ; i++){
        A[k] = i;
        if ( k == n-1) solve();
        else Try(k+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Try(0);
    return 0;
}