#include <bits/stdc++.h>
using namespace std;
const int N = 10;
bool bCol[N] = {true};
bool bDiag1[N] = {true};
int iRes[N];
int sum = 0;
bool bDiag2[N] = {true};
int n;


void Try (int i ){
    for (int j = 1 ; j <= n ; j++){
        if (bCol[j] && bDiag1[i+j] && bDiag2[i-j]){
            iRes[i] = j;
            bCol[j] = false;
            bDiag1[i+j] = false;
            bDiag2[i-j] = false;
            if ( i == n) sum++;
            else Try (i+1);
            bCol[j] = true;
            bDiag1[i+j] = true;
            bDiag2[i-j] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Try(1);

    return 0;
}