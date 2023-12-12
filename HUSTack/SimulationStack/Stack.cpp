#include <bits/stdc++.h>
using namespace std;
stack<int> S;
string str;
int n;
string tem;





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    do {
        fflush(stdin);
        getline (cin , str);
        if (str[1] == 'U')
        {
            for (int i = 5 ; i < str.length(); i++){
                tem[i-5] = str[i];
            }
            n = stoi(tem);
            S.push(n);
        }
        else if (str[1] == 'O'){
            if (!S.empty()){
                cout << S.top() << endl;
                S.pop();
            }
            else cout << "NULL" << endl;
        }
        else break;
    }
    while (str != "#");
    return 0;

}