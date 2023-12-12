#include<bits/stdc++.h>
using namespace std;
const int N = 51;
int T;
int A[N];
int res ;
int n;


void input(){
    cin >> T;
}

bool check(int v, int k ){
    for (int i = 1 ; i < k ; i++){
        if (a[i] == v) return false;
    }
    return true;
}

void Try(int k){
    for (int v = 0 ; v < 10; v++){
        if ( v == 0){
            if (k == 1 || k == 3 ) continue;
        }
        if (check(v, k)){
            a[k] = v;
            if (k == 7){
                if ((1000*a[1] + 100*a[2] + 10*a[3] + a[4] + 10000* a[3] + 1000 * a[5] + 100 * a[6] + 10 * a[7] + a[4]) == N){
                    res++;
                }
            }
            else Try(k+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    while (T--){
        res = 0;
        cin >> n;
        Try(1);
        cout << res << endl;
    }
    return 0;
}