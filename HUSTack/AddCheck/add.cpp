#include <bits/stdc++.h>
using namespace std;
stack<int> number;
stack<char> add;
string s;
string temp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int j = 0;
    for (int i = 0 ; i < s.length(); i++){
        if (i == s.length() - 1){
            temp[j] = s[i];
            int a = stoi(temp);
            number.push(a);
            break;
        }
        if (s[i] != '+'){
            temp[j] = s[i];
            j++;
        }
        else {
            if (s[i-1] == '+'){
                add.push('+');
            }
            else {
                add.push('+');
                int n = stoi(temp);
                number.push(n);
                temp = "";
                j = 0;
            }
        }
    }
    int m ,n, k ;
    while (number.size() != 1){
        m = number.top();
        number.pop();
        n = number.top();
        number.pop();
        add.pop();
        k = m + n;
        number.push(k);
    }
    if (!add.empty()) cout << "Error";
    cout << number.top();
    return 0;
}