#include <bits/stdc++.h> 
#define MAX 30
using namespace std;

int n;
int A[MAX];


void Print(int A[]){
    for (int i = 1 ; i <= n; i++){
        cout << A[i] ;
    }
    cout << endl;
}

void Try(int k){
    for (int i = 0 ; i <= 1 - A[k-1] ; i++){
        A[k] = i;
        if (k == n)
            Print(A);
        else Try(k+1);
    }
}

int main() 
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    A[0] = 0;
    Try(1);
}