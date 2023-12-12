#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int A[N];
string light;
int n;
stack<int> C;
queue<int> H;

void input(){
    cin >> n ;
    for (int i = 0 ; i < n; i++){
        cin >> A[i] ;
    }
    for (int i = n - 1 ; i >= 0 ; i--){
        C.push(A[i]);
    }
    cin >> light;
}

void solve (){
    for (int i = 0 ; i < light.length() ; i++){
        if (light[i] == 'C'){
            if (!C.empty()){
                int a = C.top();
                C.pop();
                H.push(a);
            }
        }
        else if (light[i] == 'H'){
            if (!H.empty()){
                int b = H.front();
                H.pop();
                C.push(b);
            }
        }
    }
    while (!C.empty()){
        cout << C.top() << " ";
        C.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}