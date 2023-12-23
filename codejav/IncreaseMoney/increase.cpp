#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 4;
int A[MAX];
int n;
int res = 0;
int temp = 1;

void input(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}


int solve(){
    for (int i = 0 ; i < n-1; i++){
        if (A[i] < A[i+1]){
            temp++;
        }
        else {
            res = max(res, temp);
            temp = 0;
        }
    }
    return res;
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    cout << solve() << endl;
    return 0;
}