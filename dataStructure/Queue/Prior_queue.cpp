#include <bits/stdc++.h>
using namespace std;
priority_queue<int> Q;
int A[100];
int n, k;
int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> k;
        A[i] = k;
        Q.push(k);
    }

    priority_queue<int , vector<int>, greater<int> > S(A, A + n);

    cout << Q.size() << endl;

    while (!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }

    cout << endl;

    cout << S.size() << endl;
    
    while (!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}