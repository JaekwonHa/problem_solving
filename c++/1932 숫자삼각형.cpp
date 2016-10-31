#include <stdio.h>

int N;
int tri[501][501], table[501][501];

int max(int a,int b) { return (a>b) ? a:b; }

void solve(int x, int y, int cost) {
	
	if(N<x) return;

	cost += tri[x][y];
	if(table[x][y] < cost) {
		table[x][y]=cost;

		solve(x+1,y,cost);
		solve(x+1,y+1,cost);
	}
}

void solve2() {
	table[1][1]=tri[1][1];
	for(int i=2; i<=N; i++) {
		for(int j=1; j<=i; j++) {
			int left=0,right=0;
			left = table[i-1][j-1];
			right = table[i-1][j];
			table[i][j] = max(left+tri[i][j], right+tri[i][j]);
		}
	}
}


int main() {


	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	solve2();

	int ans=0;
	for(int i=1; i<=N; i++) {
		ans = max(ans, table[N][i]);
	}

	printf("%d", ans);

	return 0;
}