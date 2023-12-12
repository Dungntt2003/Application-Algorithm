#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int A[N], iMem[N];
int n, pos;

int LIS(int i){
    if (iMem[i] != -1)
    return iMem[i];

    int res = 1;
    for (int j = 1 ; j < i ; ++j){
        if (A[j] < A[i]){
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return iMem[i];
}

void input(){
    memset(iMem, -1 , sizeof(iMem));
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
}

void Trace(int i){
    int res = 1 ;
    for (int j = i - 1 ; j > 0 ; j--){
        if (A[j] < A[i] && iMem[i] == 1 + iMem[j]){
            Trace(j);
            break;
        }
            
    }
    cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    int ans = 0;
    for (int i = 1 ; i <= n ; i++){
        ans = max(ans, LIS(i));
        if (ans = iMem[i]) pos = i;
    }
    cout << "Answer is : " << ans << endl;
    cout << "Trace : " ;
    Trace(pos);
    return 0;
}