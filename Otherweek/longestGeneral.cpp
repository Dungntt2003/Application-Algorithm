#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int iMem[N][N];
string X, Y;

int LCS(int i , int j){
    if (i == 0 || j == 0)
    return 0;
    if (iMem[i][j] != -1) return iMem[i][j];

    int res = 0;
    res = max(res, LCS(i, j-1));
    res = max(res, LCS(i-1, j));

    if (X[i] == Y[j]){
        res = max (res, 1 + LCS(i-1,j-1));
    }
    iMem[i][j] = res;
    return res;
}

void input(){
    X = "abcb";
    Y = "bdcab";
}


void Trace(int i , int j ){
    if ( i == 0 || j == 0)
    return;

    if (iMem[i][j] == iMem[i][j-1])
    Trace(i, j-1);
    return;

    if (iMem[i][j] == iMem[i-1][j]){
        Trace(i-1, j);
        return;
    }

    if (X[i] == Y[j] && iMem[i][j] == 1 + iMem[i-1][j-1]){
        Trace(i-1, j-1);
        cout << X[i] << " ";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(iMem, -1 , sizeof(iMem));
    int pos1, pos2;
    input();
    int ans = 0;
    int Xlength = X.length();
    int Ylength = Y.length();
    for (int i = 0 ; i < Xlength ; i++){
        for (int j = 0 ; j < Ylength; j++){
            ans = max (ans, LCS(i, j));
            if (iMem[i][j] == ans) {
                pos1 = i;
                pos2 = j;
            }
        }
    }
    cout << pos1 << " " << pos2 << endl;
    cout << ans << endl;
    Trace(pos1,pos2);
    return 0;
}