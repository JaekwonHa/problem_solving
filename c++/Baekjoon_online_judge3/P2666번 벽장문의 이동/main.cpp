#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 987654321

int N,c,arr[21],DP[21][21][21],door[21];

int f(int x, int l, int r) {
	if(x==c) return 0;

	int ret=INF,a,b;

	ret = DP[x][l][r];
	if(ret == -1) {
		ret = INF;
		a = abs(l-door[x]);
		b = abs(r-door[x]);
		
		a = a+f(x+1,door[x],r);
		b = b+f(x+1,l,door[x]);

		if(a<b)
			ret = DP[x][l][r] = a;
		else
			ret = DP[x][l][r] = b;
	}

	return ret;
}

int main() {
	memset(DP,-1,sizeof(DP));
	scanf("%d", &N);
	int a,b;
	scanf("%d %d", &a, &b);
	arr[a]=1, arr[b]=1;

	scanf("%d", &c);
	for(int i=0; i<c; i++)
		scanf("%d", &door[i]);

	printf("%d\n", f(0,a,b));

	return 0;
}