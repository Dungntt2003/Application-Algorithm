#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int A[N];

void solve(){
    for (int i = 1 ; i <= n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for (int i = 0 ; i <= 1; i++){
        A[k] = i;
        if ( k == n) solve();
        else Try(k+1); 
    }
}

int main(){
    cin >> n;
    Try(1);
    return 0;
}