#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int iMem[N][1 << N];
int C[N][N];
int n;
const int INF = -1e6;

int TSP(int i, int S){
    if (S== ((1 << n) -1 )) return C[i][0];
    if (iMem[i][S] != -1) return iMem[i][S];

    int res = INF;
    for (int j = 0 ; j < n; j++){
        if (S & (i << j))
        continue;
        res = min(res, C[i][j] + TSP(j , S | (i << j)));
    }
    iMem[i][S] = res;
    return res;
}

void Trace(int i , int S){
    cout << i << " ";
    if ( S == ((1 << n) - 1)) return ;
    int res = iMem[i][S];

    for (int j = 0 ; j < n; j++){
        if (S & (i << j))
        continue;
        if (res == C[i][j] + iMem[j][S | (1 << j)]){
            Trace(j , S | (1 << j));
            break;
        }
    }
}

void input(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (j = 0 ; j < n ; j++){
            cin >> C[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(iMem, -1 , sizeof(iMem));
    input();
    cout << TSP(0 , 1 << 0) << endl;
    Trace(0, 1 << 0);

    return 0;
}