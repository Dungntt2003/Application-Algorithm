#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
const float MIN = -10000000;
int n, k;
float res;
int A[N];

void input(){
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}

float Avg(int i , int j){
    if (j - i + 1 < k) return MIN;
    int sum = 0;
    for (int x = i ; x <= j ; x++){
        sum += A[x];
    }
    return (float)sum/(j-i+1);
}

void solve(){
    res = 0;
    for (int i = k ; i < n ; i++ ){
        for (int j = 0 ; j < i ; j++){
            res = max(res, Avg(i,j));
        }
    }
    cout << res << endl; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}