#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, M;
int A[MAX];
bool B[MAX] = {false};

int Count(){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n ; j++){
            if (!B[i] && !B[j] && A[i] + A[j] == M){
                count ++;
                B[i] = true;
                B[j] = true;
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for (int i = 0; i < n ; i++){
        cin >> A[i];
    }
    cout << Count();
    return 0;
}