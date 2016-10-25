#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int N,M;
int DP[110][10100];
int W[110],V[110][15];

int f(int n, int money) {
	if(money<=0 || n<=0) return 0;

	int& ret=DP[n][money];
	if(ret != -1) return ret;

	ret=0;
	int i=n;
	for(int j=0; j<=V[i][0]; j++) {
		if(j==0) {
			ret = max(ret, f(i-1,money));
		} else {
			if(money-W[i]*j >= 0) {
				ret = max(ret, f(i-1,money-W[i]*j)+V[i][j]);
			}
		}
	}
	return ret;
}

int main() {

	cin>>N>>M;
	int t,s;
	for(int i=1; i<=N; i++) {
		cin>>W[i]>>V[i][0];
		s=0;
		for(int j=1; j<=V[i][0]; j++) {
			cin>>t;
			s += t;
			V[i][j] = s;
		}
	}
	memset(DP,-1,sizeof(DP));
	cout<<f(N,M)<<endl;


	return 0;
}