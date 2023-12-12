#include <bits/stdc++.h>
using namespace std;

map <int, int> Mem;
int fibo (int n){
    if ( n <= 2 ) return 1;
    if (Mem.find(n) != Mem.end())
        return Mem[n];
    int res = fibo(n-1) + fibo(n-2);
    Mem[n] = res ;
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n ;
    cin >> n;
    cout << fibo(n);
    return 0;
}