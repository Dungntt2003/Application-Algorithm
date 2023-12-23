#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const long long INF = 1e9 + 7; 
int n;
int A[N];
int res = 0;

void input(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}

void solve(int k){
    int sum = A[k];
    if (A[k] % 2 ) res++;
    for (int i = k + 1 ; i < n ; i++){
        if (sum % 2 == 0 && A[i] % 2 == 0){
            res++;  
        }
        else if (sum % 2 != 0 && A[i] % 2 != 0){
            res++;
        }
        sum += A[i];
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    for (int i = 0 ; i < n ; i++){
        solve(i);
    }
    cout << res % INF << endl;
    return 0;
}