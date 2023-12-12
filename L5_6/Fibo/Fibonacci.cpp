#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int Mem[N];
int A[N];
int n;

int Fibo (int k){
    if ( k == 1 || k == 2 ) return 1;
    if (Mem[k] != -1) return Mem[k];

    int res = Fibo(k-1) + Fibo(k-2);
    return Mem[k] = res;
}

int main(){
    memset(Mem, -1 , sizeof(Mem));
    cin >> n;
    cout << Fibo(n) << endl;
    return 0;
}