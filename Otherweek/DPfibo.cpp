#include <bits/stdc++.h>
#define MAX 100
using namespace std;

map <int, int> Mem;

int n;
int mem[MAX];

// ver1
int DP(int n){
    if ( n<= 2 ) return 1;
    return DP(n-1) + DP(n-2);
}

// ver2
int DP1(int n){
    if ( n <= 2 ) return 1;
    if (mem[n] != -1) return mem[n];
    int res = DP1(n-1) + DP1(n-2);
    return mem[n] = res;
}
// ver3
int DP2(int n){
    if ( n<= 2 ) return 1;
    if (Mem.find(n) != Mem.end()) return Mem[n];
    int res = DP2(n-1) + DP2(n-2);
    return Mem[n] = res;
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    auto start = chrono::high_resolution_clock::now();
    memset(mem,-1, sizeof(mem));
    cin >> n;
    // for (int i = 0 ; i <= n; i++)
    // cout << mem[i] << " ";
    // cout << endl;
    cout << "Fibo la : "  << DP2(n) << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double time = duration.count();
    cout << "Thoi gian thuc hien " << time << endl;
    return 0;
}