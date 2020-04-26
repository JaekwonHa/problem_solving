#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T,N,M,C;
int c[50],d[100010];
int DP[100010][50];

int f(int num, int prev) {
	if(num>N) return 0;

	int &ret = DP[num][prev];
	if(ret != -1) return ret;

	int a,b;
	if(d[num] == prev) {
		ret = f(num+1,prev);
	} else {
		a = f(num+1,d[num]) + C;
		b = f(num+1,prev) + c[d[num]];
		ret = min(a,b);
	}
	return ret;
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &N, &M, &C);
		memset(DP, -1, sizeof(DP));

		for(int i=1; i<=M; i++) {
			scanf("%d", &c[i]);
		}
		for(int i=1; i<=N; i++) {
			scanf("%d", &d[i]);
		}

		//printf("%d\n", min(f(2,1)+C, f(2,0)+c[d[1]]));
		printf("%d\n", f(1,0));
	}

	return 0;
}