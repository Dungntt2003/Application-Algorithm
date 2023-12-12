#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int A[N];

int MaxLeft(int i , int mid){
    int max1 = A[mid];
    int s = 0;
    for (int k = mid ; k >= i ; k--){
        s += A[k];
        max1 = max(max1, s);
    }
    return max1;
}

int MaxRight(int mid , int j){
    int max2 = A[mid];
    int s = 0;
    for (int i = mid; i <= j ; i++){
        s += A[i];
        max2 = max(max2, s);
    }
    return max2;
}

int SubSeqMax(int i , int j){
    if ( i == j ) return A[i];
    int mid = (i + j) /2;
    int maxL = SubSeqMax(i, mid);
    int maxR = SubSeqMax(mid + 1, j);
    int maxSubL = MaxLeft(i, mid);
    int maxSubR = MaxRight(mid + 1, j);
    int maxG = maxSubL + maxSubR;
    int res = maxL;
    res = max(res, max(maxR, maxG));
    return res;
}


void input ()
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> A[i];
}
int main(){
    input();
    cout << SubSeqMax(0, n-1);
    return 0;
}