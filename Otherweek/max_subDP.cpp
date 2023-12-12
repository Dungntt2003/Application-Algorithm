#include <bits/stdc++.h>
#define MAX 100;
using namespace std;


int A[MAX];
bool marked[MAX];
int mem[MAX];
int n;
memset(marked,0,sizeof(marked));

int DP(int n){
    if ( n == 1) return A[n];
    if (marked[n])
    return mem[n];
    int res = max (A[n],A[n] + DP(n-1) );
    marked[n] = true;
    return mem[n] = res;
}

void Trace(int i){
    if (i != 1 && mem[i] = A[i] + mem[i-1])
    Trace(i-1);
    cout << A[i] << "   ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> A[i];
    }
    cout << "Tong con lon nhat la " << DP(n);
    cout << endl;
    Trace(n);
    cout << endl;
    return 0;
}