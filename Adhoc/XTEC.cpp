#include <bits/stdc++.h>
using namespace std;
int A[5];
int T;
 
 void input(){
    for (int i = 0 ; i < 4 ; i++){
        cin >> A[i];
    }
 }


void solve (){
    sort(A, A+4);
    if (A[0] < 0 && A[1] < 0)
    cout << A[0] + A[1] << endl;
    else if (A[0] < 0)
    cout << A[0] << endl;
    else cout << 0;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 0 ; i < T ; i++){
        input();
        solve();
    }
    return 0;
}