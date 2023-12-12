#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int A[MAX];
int n;


int Maxleftmid(int i, int j){
    int maxLM = A[j];
    int s = 0;
    for (int k = j; k >= i; k--){
        s += A[k];
        maxLM = max(s, maxLM);
    }
    return maxLM;
}

int Maxrightmid (int i , int j){
    int maxRM = A[i];
    int s = 0;
    for (int k = i ; k <= j ; k++){
        s += A[k];
        maxRM = max(s, maxRM);
    }
    return maxRM;
}


int SubseqMax(int i, int j){
    if ( i == j) return A[i];
    int mid = (i+j)/2;
    int wL = SubseqMax(i , mid);
    int wR = SubseqMax(mid+1,j);
    int maxLM = Maxleftmid(i, mid);
    int maxRM = Maxrightmid(mid + 1 , j);
    int wM = maxLM + maxRM;
    return max (max(wL,wR),wM);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <=n ; i++){
        cin >> A[i];
    }
    cout << SubseqMax(1,n);
    return 0;
}