#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int A[N];
int Mem[N] ;
bool bMarked[N] = {false};

int MaxSeq (int i){
    if (i == 1) return A[1];
    if (bMarked[i]) return Mem[i];
    int res = max(MaxSeq(i-1) + A[i], A[i]);
    bMarked[i] = true;
    return Mem[i] = res;
}

void input(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
}

void Trace(int i){
    if (i != 1 && Mem[i] == A[i] + Mem[i-1]){
        Trace(i-1);
    }
    cout << A[i] << " ";
}

int main(){
    input();
    int result = MaxSeq(1);
    int pos;
    for (int i = 1 ; i <= n ; i++){
        result = max(result, MaxSeq(i));
        pos = i;
    }
    cout << result << endl;
    Trace(pos);
    return 0;
}