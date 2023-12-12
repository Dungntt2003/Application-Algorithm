#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int D[N];
int x;
int iMem[N][N];
const int INF = 1e6;

int Money(int i, int x){
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == 0) return INF;
    if (iMem[i][x] != -1) return iMem[i][x];

    int res = INF;
    res = min(res, 1 + Money(i, x - D[i]));
    res = min(res, Money(i-1, x));
    return iMem[i][x] = res;
}

void input (){
    cin >> x;
    for (int i = 1; i <= 5 ; i++){
        cin >> D[i];
    }
}

int main(){
    memset(iMem, -1 , sizeof(iMem));
    input();
    int result = 1e5;
    for (int i = 1; i <= 5 ; i++){
        result = min(result, Money(i, x));
    }
    cout << result;
    return 0;
}