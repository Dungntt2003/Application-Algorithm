#include<bits/stdc++.h>
using namespace std;
const int M = 1e3;

int N, cap, c[2 * M + 1][2 * M + 1], x[M], appear[M], load, f, f_best, x_best[M], cmin;

void input(){
	cin >> N >> cap;
	cmin = 1e6;
	for(int i = 0; i <= 2*N; i++){
		for (int j = 0; j <= 2*N; j++){
			cin >> c[i][j];
			if(i != j && c[i][j] < cmin){
				cmin = c[i][j];
			}
		}
	}
}

bool check(int v, int k){
	if(appear[v] == 1) return false;
	if(v > N){
		if(!appear[v - N]) return false;
	}
	else{
		if(load + 1 > cap) return false;
	}
	return true;
}

void solution(){
	if(f + c[x[2*N]][0] < f_best){
		f_best = f + c[x[2*N]][0];
		for(int i = 0; i <= 2*N; i++){
			x_best[i] = x[i];
		}
	}
}

void Try(int k){
	for(int v = 1; v <= 2 * N; v++){
		if(check(v, k)){
			x[k] = v;
			f += c[x[k - 1]][x[k]];
			if(v <= N){
				load += 1;
			}
			else{
				load -= 1;
			}
			appear[v] = 1;
			if(k == 2*N){
				solution();
			}
			else{
				if(f + (2*N + 1 - k)*cmin < f_best){
					Try(k + 1);
				}
			}
			if(v <= N){
				load -= 1;
			}
			else{
				load += 1;
			}
			appear[v] = 0;
			f -= c[x[k - 1]][x[k]];
		}
	}
}

void solve(){
	load = 0;
	f = 0;
	f_best = 1e6;
	for(int i = 1; i <= 2*N; i++){
		appear[i] = 0;
	}
	x[0] = 0;
	Try(1);
	cout << f_best;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}
