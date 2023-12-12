#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int C[N][N];
int A[N];
int cmin = 0;
int f = 0;
int f0 = 1e5;
bool bVisited[N] = {false};
int g;
void input (){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            cin >> C[i][j];
            cmin = min(cmin, C[i][j]);
        }
    }
}


void Try (int k){
    for (int i = 1 ; i <= n ; i++){
        if (!bVisited[i]){
            A[k] = i;
            bVisited[i] = true;
            f += C[A[k-1]][A[k]];
            if (k == n){
                if (f + C[A[k]][1] < f0){
                    f0 = f + C[A[k]][1];
                }
            }
            else {
                g = f + (n - k + 1) * cmin;
                if ( g < f0){
                    Try(k+1);
                }
            }
            bVisited[i] = false;
            f -= C[A[k-1]][A[k]];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    bVisited[1] = true;
    A[1] = 1;
    Try(2);
    cout << f0 << endl;
    return 0;
}