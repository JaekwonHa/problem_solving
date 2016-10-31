#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10010

int T,K,P[101],N[101],DP[101][10010];

int f(int x, int t) {
	if(x<0) {
		if(t==0) return 1;
		return 0;
	}
	int ret = DP[x][t];
	if(ret==-1) {
		ret=0;
		for(int i=0; i<=N[x]; i++) {
			if(t-P[x]*i <0) break;
			ret += f(x-1,t-P[x]*i);
		}
		DP[x][t]=ret;
	}
	return ret;
}

int main() {

	scanf("%d", &T);
	scanf("%d", &K);
	for(int i=0; i<K; i++)
		scanf("%d %d", &P[i], &N[i]);


	for(int i=0; i<K; i++) fill(DP[i],DP[i]+T+1,-1);
	printf("%d\n", f(K-1,T));

	return 0;
}