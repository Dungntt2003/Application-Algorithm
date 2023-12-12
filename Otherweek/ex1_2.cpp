#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
// a1 * x1 + a2 * x2 + ... + an * xn = M
// biet x(k-1) tinh x(k)
// x(k) = M - a1*x1 - .. - a(k-1) * x(k-1) - ( a(k+1) + ... an) : a(k)
// 1 .. M - a1*x1 - .. - a(k-1) * x(k-1) - ( a(k+1) + ... an) : a(k)

int A[MAX];
int n, M;
int f, m0;
int B[MAX];
int number = 0;

int Sum (int i, int j){
    int sum;
    for (int v = i; v <= j; v++)
    sum += A[v];
    return sum;
}

// void Print(){
//     for (int i = 1 ; i <= n ; i++){
//         cout << B[i];
//     }
//     cout << endl;
// }


void Try (int k){
    m0 = (M - f - (Sum(k+1,n)))/A[k];
    for (int i = 1; i <= m0; i++){
        B[k] = i;
        f += A[k]*B[k];
        if ( k == n && f == M)
        {
            cout << "Number : "  << number << endl;
            number++;
        }
        else Try(k+1);
        f -= A[k]*B[k];
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    f = 0;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    Try(1);
    cout << number;
    return 0;
}