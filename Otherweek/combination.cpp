#include <bits/stdc++.h> 
#define MAX 100
using namespace std;

int m , n;
int A[MAX];

void Print(int A[]){
    for (int i = 1; i <= m; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Try (int k ){
    for (int i = A[k-1] + 1 ; i <= n-m+k ; i++){
        A[k] = i;
        if ( k == m ) Print(A);
        else Try(k+1);
    }
}


int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    A[0] = 0;
    Try(1);
    return 0;
}