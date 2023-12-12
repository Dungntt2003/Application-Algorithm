#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, k;
int A[N];
bool bMarked[N] = {false};

void solve(){
    for (int i = 1 ; i <= k ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try (int m){
    for (int i = 1 ; i <= n ; i++){
        if (!bMarked[i]){
            A[m] = i;
            bMarked[i] = true;
            if ( m == k ) solve();
            else Try(m+1);
            bMarked[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    Try(1);
    return 0;
}