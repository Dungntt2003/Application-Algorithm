#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int A[N];
int ans = 0;
int n, a , b;


void input (){
    cin >> n >> a >> b;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}

void solve(){
    for (int i = 0 ; i < n ; i++){
        int sum = A[i];
        for (int j = i+1 ; j < n ; j++){
            sum += A[j];
            if ( a <= sum && sum <= b) ans++;
            if (sum > b) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    cout << ans << endl;
    return 0;
}