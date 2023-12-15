#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int n, k;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> k;
        V.push_back(k);
    }

    for (int i = 0 ; i < n ; i++){
        cout << V[i] << " ";
    }
    cout << endl;
    for (auto i = V.begin(); i != V.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    cout << V[1] << " " << V.at(2) << " " << V.back() << " " << V.front() << endl;

    V.push_back(10);
    V.pop_back();

    V.insert(V.begin(), 11);
    V.erase(V.begin());

    for (auto i = V.begin(); i != V.end(); i++){
        cout << *i << " ";
    }
    return 0;
}