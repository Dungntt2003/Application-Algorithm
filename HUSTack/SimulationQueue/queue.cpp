#include <bits/stdc++.h>
using namespace std;
string str;
int n;
string temp;
queue<int> Q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    do {
        getline(cin, str);
        if (str[1] == 'U'){
            for (int i = 5 ; i < str.length(); i++){
                temp[i-5] = str[i];
            }
            n = stoi(temp);
            Q.push(n);
        }
        else if (str[1] == 'O'){
            if (!Q.empty()){
                cout << Q.front() << endl;
                Q.pop();
            }
            else cout << "NULL" << endl;
        }
        else break;
    }
    while (str != "#");
    return 0;
}