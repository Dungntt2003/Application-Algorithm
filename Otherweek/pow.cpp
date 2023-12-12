#include <bits/stdc++.h>
using namespace std;




int Pow (int x, int n){
    if ( n == 0) return 1;
    if ( n % 2 != 0) return x * Pow(x , n-1);
    int res = Pow (x, n/2);
    return res * res;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    clock_t start, end;
    double time_use;
    int x, n;
    cin >> n >> x;
    start = clock();
    cout << Pow(x, n) << endl;
    end = clock();
    time_use = (double) (end - start) / CLOCKS_PER_SEC;
    cout << time_use;
    return 0;
}