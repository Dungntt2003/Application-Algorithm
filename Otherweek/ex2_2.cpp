#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int A[MAX];
int c[MAX][MAX];
int f , n, f0, g, load, capture;
bool marked[MAX] = {false};

bool check (int v, int k){
    if (marked[v]) return false;
    if ( v > n) {
        if (!marked[v-n]) return false;
    }
    if (load + 1 > capture) return false;
    return true;
}

int Find_min(){
    min = c[1][1];
    for (int i = 1 ; i <= n; i++){
        for (int j = 1 ; j <= n; j++){
            if (min > c[i][j] && i != j) min = c[i][j];
        }
    }
    return min;
}

void Print(){
    for (int i = 1 ; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try (int k){
    for (int i = 2 ; i <= n ; i++){
        if (!marked[i]){
            A[k] = i;
            marked[i] = true;
            f = f + c[A[k-1], A[k]];
            if ( k == n ){
                if (f + c[A[k]][1] < f0){
                    Print();
                }       
            }
            else {
                g = f + (n - k + 1)*Find_min();
                if (g < f0) Try(k+1);
            }
            f = f + c[A[k-1], A[k]];
            marked[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cin >> c[i][j];
        }
    } 
    f = 0;
    f0 = INT_MAX;
    A[1]= 1;
    marked[1] = true;
    Try(2);
    return 0;
}