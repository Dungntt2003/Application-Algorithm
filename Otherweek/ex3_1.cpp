#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int A[MAX];
int n;
int k;
int FindMin(int i, int j){
    int min = A[i];
    for (int v = i + 1 ; v <= j ; v++){
        if ( A[v] < min ) min = A[v];
    }
    return min;
}
// FindMin version 2
// int FindMin_v2 (int i, int j){
//     int min = FindMin(i - 1, j);
//     if (min > A[i]) return A[i];
//     return min;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int count = 0;
    int m, o;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    cin >> k;
    for (int i = 0 ; i < k ; i++){
        cin >> m;
        cin >> o;
        count += FindMin(m, o);
    }
    cout << count << endl;
    return 0;
}