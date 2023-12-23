#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int n;
int A[N];
set<int> Q;
string s;
string b;
int a;


void input (){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
        Q.insert(A[i]);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    getline(cin, s);
    while (getline(cin, s) && s != "*"){
        if (s[0] == 'i'){
            stringstream ss(s);
            ss >> b >> a;
            Q.insert(a);
        }
        else {
            auto element = max_element(Q.begin(), Q.end());
            if (element != Q.end()){
                cout << *element << endl;
                Q.erase(*element);
            }
        }
    }
    return 0;
}