#include<bits/stdc++.h>
using namespace std;

int INF = 100000;
int D[11];
int iMem[11][100001];
memset(iMem,-1,sizeof(iMem));


int MinCoin (int i, int x){
    if ( x < 0 ) return INF;
    if ( x == 0 ) return 0;
    if (i == 0) return INF;

    if (iMem[i][x] != -1) return iMem[i][x];
    int res = INF;
    res = min(res, MinCoin(i, x-D[i]));
    res = min (res, MinCoin(i-1,x));
    iMem[i][x] = res;
    return res;
}
void Trace(int i, int x){
    if ( x < 0) return;
    if (x == 0) return ;
    if ( i == 0) return ;
    int res = INF;
    if (iMem[i][x]== 1 + iMem[i][x-D[i]]){
        cout << D[i] << " ";
        Trace(i, x-D[i]);
    }
    else {
        Trace(i-1, x);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}