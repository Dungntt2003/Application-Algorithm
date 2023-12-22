#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
const long long INF = 1e9 + 7;
int k, n;
int A[MAX];
int res = 0;

void Try(int m){
    for (int i = A[m-1]+1 ; i <= n-k+m; i++){
        A[m] = i;
        if (m == k) res++;
        else Try(m+1);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    A[0] = 0;
    Try(1);
    cout << res % INF << endl;
    return 0;
}