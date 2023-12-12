#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int A[N];
int n;
bool bmark[N] = {false};

void solve(){
    for (int i = 1 ; i <= n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


void Try(int k){
    for (int i = 1 ; i <= n ; i++){
        if (!bmark[i]){
            A[k] = i;
            bmark[i] = true;
            if (k == n){
                solve();
            }
            else Try(k+1);
            bmark[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Try(1);
    return 0;
}