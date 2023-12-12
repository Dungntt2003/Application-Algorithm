#include <bits/stdc++.h>
using namespace std;
string X = "abcdab";
string Y = "abcd";
int n1, n2;
const int N = 1e4 ;
int iMem[N][N];

int MaxGenal(int i , int j){
    if (i == 0 || j == 0) return 0;
    if (iMem[i][j] != -1) return iMem[i][j];
    int res = MaxGenal(i, j-1);
    res = max(res, MaxGenal(i, j-1));
    if (X[i] == Y[j]){
        res = max(res, 1 + MaxGenal(i-1, j-1));
    }
    return iMem[i][j] = res;
}



int main(){
    n1 = X.length();
    n2 = Y.length();
    int result = 0;
    for (int i = 0 ; i < n1 ; i++){
        for (int j = 0 ; j < n2 ; j++){
            result = max(result, MaxGenal(i,j));
        }
    }
    cout << result << endl;
    return 0;
}