#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+ 4;
int A[N];
int n, m, k;
int ans = 0;

void input(){
    cin >> n >> k >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i] ;
    }
}

void solve(){
    int sum ;
    for (int i = 0 ; i < n ; i++){
        sum = A[i];
        for (int j = i+1; j < n ; j++){
            sum += A[j];
            if (sum == m && j - i + 1 == k) {
                ans++;
                break;
            }
            else if (j - i + 1 > k) break;
            else if (sum > m) break;
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