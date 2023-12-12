#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int n;
int A[N];
int res = 1;

void input(){
    cin >> n ;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}

void run(){
    for (int i = 0 ; i < n - 1; i++){
        if (A[i] > A[i+1]){
            res++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    run();
    cout << res << endl;
    return 0;
}