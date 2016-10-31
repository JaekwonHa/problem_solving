#include <stdio.h>
#define MAXV 999999

int n,M, ans=0x7fffffff;
int m[100];
int c[100];

void dfs(int bound, int Memory, int cost) {
	if(cost > ans) return;
	if(Memory >= M) {
		if(cost < ans) ans=cost;
		return;
	}
	for(int i=bound; i<n; i++) {
		dfs(i+1, Memory+m[i], cost+c[i]);
	}
}

int min(int a, int b) { return a<b?a:b; }

int f(int i, int r) {
	if(i==0) {
		if(r<=0) return 0;
		else return MAXV;
	} else if(r<0)
		return f(i-1, r);
	else
		return min(f(i-1,r), f(i-1,r-m[i])+c[i]);
}

int main() {

	scanf("%d %d", &n, &M);
	for(int i=0; i<n; i++)
		scanf("%d", &m[i]);
	for(int i=0; i<n; i++)
		scanf("%d", &c[i]);

	//dfs(0, 0, 0);
	//printf("%d", ans);
	printf("%d", f(n,M));

	return 0;
}