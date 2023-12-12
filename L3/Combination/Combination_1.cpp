#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 20;
int A[N];

void solve(){
    for (int i = 1 ; i <= k ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int m){
    for (int i = A[m-1] + 1 ; i <= n - k + m ; i++){
        A[m] = i;
        if ( m == k ) solve();
        else Try(m+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    Try(1);


    return 0;
}