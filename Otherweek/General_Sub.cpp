#include <bits/stdc++.h>
using namespace std;

string X = "abcb";
string Y = "bdcab";
int Mem[100][100];
memset(Mem, -1, sizeof(Mem));

int General(int i, int j){
    if (i == 0 || j == 0)
    return 0;
    if (Mem[i][j] != -1) return Mem[i][j];
    int res = 0;
    res = max (res, General(i-1,j));
    res = max (res,General(i, j-1));
    if ( X[i] = Y[j])
     res = max(res, 1 + General(i-1, j-1));
    return Mem[i][j] = res;
}

void Trace(int i, int j ){
    if (i == 0 || j == 0){
       return ; 
    }
    if ( Mem[i][j] == Mem[i-1][j]){
        Trace(i-1,j);
        return;
    }
    if (Mem[i][j] == Mem[i][j-1])
    {
        Trace(i, j-1);
        return ;
    }
    if (X[i]== Y[j] && Mem[i][j] == 1 + Mem[i-1][j-1]){
        Trace(i-1,j-1);
        cout << X[i] << " ";
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.toe(0); cout.tie(0);
    General(X.length(), Y.length());
    Trace(X.length(), Y.length())
    return 0;
}