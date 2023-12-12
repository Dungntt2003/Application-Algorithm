#include <bits/stdc++.h> 
#define MAX 21
using namespace std;

int A[MAX];
int n;
bool marked[MAX] = {false};

void Print(){
    for (int i = 1; i <= n ; i++)
    cout << A[i] << " ";
    cout << endl;
}

void Try (int k ){
    for ( int i = 1; i <=n ; i++){
        if (!marked[i])
        {
            A[k] = i;
            marked[i] = true;
            if ( k == n) Print();
            else Try(k+1);
            marked[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n ;
    Try(1);
    return 0;
}