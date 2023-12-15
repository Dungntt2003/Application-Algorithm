#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
int A[N];
int n,m;
int res = 0;


int minOf(int i , int j){
    int ans = A[i];
    for (int k = i + 1; k <= j ; k++){
        ans = min(ans, A[k]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    cin >> A[i];
    cin >> m;
    int u, v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        res += minOf(u,v);
    }
    cout << res;
    return 0;
}