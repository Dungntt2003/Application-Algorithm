#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int Result[MAX];
int c[MAX][MAX];
int g, f, f0, n;
bool marked[MAX] = {false};
int cmin;

int Min(){
    int min = 1;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            if (c[i][j] < min && i != j) min = c[i][j];
        }
    }
    return min;
}


void Try (int k ){
    for (int v = 2 ; v <= n ; v++){
        if (!marked[v]){
            Result[k] = v;
            marked[v] = true;
            f = f + c[Result[k-1]][Result[k]];
        
        if ( k == n )
        {
            if ( f + c[Result[n]][Result[1]] < f0){
                f0 = f + c[Result[n]][Result[1]];
            }
        }
        else {
            g = f + (n - k + 1) * cmin;
            if (g < f0) Try(k+1);
        }
        f = f - c[Result[k-1]][v];
        marked[v] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            cin >> c[i][j];
        }
    }
    f0 = INT_MAX;
    f = 0;
    cmin = Min();
    Result[1] = 1;
    marked[1] = true;
    Try(2);
    cout << f0;
    return 0;
}