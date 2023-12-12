#include <bits/stdc++.h>
using namespace std;
char smsArray[] =  {'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
int Array[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1};
int T;
string str;

void input(){
    fflush(stdin);
    cin >> str;
}

int Add(char a, char *smsArray){
    for (int i = 0 ; i < 25 ; i++){
        if (smsArray[i] == a){
            return i;
        }
    }
    return -1;
}

int solve(){
    int res = 0;
    int n = str.length();
    for (int i = 0 ; i < n ; i++){
        res += Array[Add(str[i], smsArray)];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 0 ; i < T ; i++){
        input();
        cout << "Case #" <<  i + 1 << " : " << solve() << endl; 
    }

    return 0;
}