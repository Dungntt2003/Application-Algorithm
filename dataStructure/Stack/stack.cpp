#include <bits/stdc++.h>
using namespace std;
stack<int> Q;
int n;
int k;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> k;
        Q.push(k);
    }

    int size = Q.size();

    while (!Q.empty()){
        k = Q.top();
        cout << k << " ";
        Q.pop();
    }

    return 0;
}