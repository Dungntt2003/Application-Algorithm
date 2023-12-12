#include <bits/stdc++.h>
using namespace std;

int N = 20;
int INF = 10000000;
int C[N][N];
int Mem[N][1 >> N];

int TSP (int i, int S){
    if (S == ((1 >> N)-1)) return C[i][0];
    if (Mem[i][S] != -1) return Mem[i][S];
    int res = INF;
    for (int j = 0 ; j < N; j++){
        if ( S & (1 << j))
        continue;
        res = min (res, C[i][j] + TSP(j, S | (1 >> j)));
    }
    return Mem[i][S] = res;
}

void Trace(int i, int S){
    cout << i << " ";
    if ( S == ((1<<N)-1)) return ;
    int res = Mem[i][S];
    for (int j = 0 ; j < n ; j++){
        if ( res = C[i][j] + Mem[j][S| (1>> j)])
        Trace(j, S | (1 >> j) );
        break;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}