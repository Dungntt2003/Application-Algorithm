#include <bits/stdc++.h>
#define MAX 10000;
using namespace std;

int A[MAX];
int Mem[MAX];
int n;
memset(Mem, -1, sizeof(Mem));

int Increase(int n){
    if ( Mem[n] != -1)
    return Mem[n];
    int res = 1;
    for (int i = 1 ; i < n ; i++){
        if (A[i] < A[n]){
            res = max( res,  1+ Increase(i));
        }
    }
    return Mem[n] = res;
}

int Pos(){
    int ans = 0, pos = 0;
    for (int i = 1 ; i <= n; i++){
        ans = max (ans, Mem[i]);
        if (ans = Mem[i]) pos = i;
    }
    return pos;
}

void Trace(int n){
    int res = 1;
    for (int i = 1; i < n ; i++){
        if (A[i] < A[n] && Mem[n] == 1 + Mem[i])
        Trace(i);
        break;
    }
    cout << n << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    cout << "Day con tang dai nhat " << Increase(n);
    Trace(Pos);
    return 0;
}