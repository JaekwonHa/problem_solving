#include <stdio.h>

int map[10][10];
int col[10];
int n, ans=0x7fffffff;

void dfs(int r, int sum) {
	if(r == n) {
		if(sum < ans) ans=sum;
		return;
	}
	for(int i=0; i<n; i++) {
		if(col[i]==0) {
			col[i]=1;
			dfs(r+1, sum+map[r][i]);
			col[i]=0;
		}
	}
}

int main() {

	scanf("%d",	&n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",	&map[i][j]);

	dfs(0,0);

	printf("%d", ans);

	return 0;
}