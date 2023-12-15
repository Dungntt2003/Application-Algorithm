#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
int n, k;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> k;
        Q.push(k);
    }

    cout << Q.size() << endl;

    while (!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}