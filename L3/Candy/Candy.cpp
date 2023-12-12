#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 20;
int A[N];
int m0 = 0;
int m1;

void solve(){
    for (int i = 1 ; i <= n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    if ( k == n){
        A[k] = m - m0;
        solve();
        return;
    } 
    m1 = m - m0 - (n - k);

    for (int i = 1 ; i <= m1 ; i++){
        A[k] = i;
        m0 += A[k];
        Try(k+1);
        m0 -= A[k];
    }

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    Try(1);
    return 0;
}