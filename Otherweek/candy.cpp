#include <bits/stdc++.h>
#define MAX 41
using namespace std;
// x1 + x2 + ... + xn = m (x1, ... , xn > 0)
int A[MAX];
int n;
int f;
int m0;
int m;

void Print(){
    for (int i = 1 ; i <= n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try( int k ){
    if ( k == n && ((m - f) >= A[k-1]))
    {
        A[k] = m - f;
        return Print();
    }
    m0 = m - f - (n - k);
    for (int i = A[k-1] ; i <= m0 ; i++){
        A[k] = i;
        f += i;
        Try(k+1);
        f -= i;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f = 0;
    A[0] = 1;
    Try(1);
    return 0;
}