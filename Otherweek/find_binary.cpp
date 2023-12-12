#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int A[MAX];
int n;
int x;

void Sort(){
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            if ( A[i] > A[j] )
            {
                int tem = A[i];
                A[i] = A[j];
                A[j] = tem;
            }
        }
    }
}

void Print(){
    for (int i = 0; i < n ; i++)
    cout << A[i] << " ";
    cout << endl;
}

int Find (int i , int j, int x){
    int mid = (i + j)/2;
    if (A[mid] == x) return mid;
    if ( x < A[mid]) return Find(i, mid-1,x);
    else return Find(mid+1, j, x);
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    Sort();
    Print();
    cin >> x;
    cout << Find(1, n, x);
    return 0;
}