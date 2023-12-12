#include<iostream>
using namespace std;
const int N = 1e3;
int n, M, f;
int count; 
int a[N], t[N], X[N];

void initT(){
	t[1] = a[1];
	for(int i = 2; i <= n; i++){
		t[i] = t[i-1] + a[i];
	}
}

void Try(int k){
	for(int v = 1; v <= (M - f - (t[n] - t[k])) / a[k]; v++){
		X[k] = v;
		f += a[k] * X[k];
		if(k == n){
			if(f == M){
				count++;
			}
		}
		else{
			Try(k + 1);
		}
		f -= a[k] * X[k];
	}
}

void solve(){
	f = 0;
	initT();
	count = 0;
	Try(1);
	cout << count;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> M;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	solve();
	return 0;
}
