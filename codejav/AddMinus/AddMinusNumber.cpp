#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int A[N];
int n, b;
char B[2] = {'+', '-'};
int res = 0;
int ans = 0;

void input(){
    cin >> n >> b;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
}

void Try(int k){
    for (int i = 0 ; i < 2 ; i++){
        if (B[i] == '+'){
            ans = ans + A[k];
        }
        else if (B[i] == '-')
        ans = ans - A[k];
        if ( k == n && ans == b) {
            res++;
        }
        else if (k == n){
            res = res + 0;
        }
        else Try(k+1);
        if (B[i] == '+'){
            ans = ans - A[k];
        }
        else if (B[i] == '-')
        ans = ans + A[k];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    Try(1);
    cout << res << endl;
    return 0;

}