#include <stdio.h>

int n,m,ans=987654321;
int map[11][11];
int visited[11];

void dfs(int x, int weight) {
	if(weight >= ans) return;
	if(x == n) {
		if(weight < ans) ans=weight;
		return;
	}
	visited[x]=1;
	for(int i=1; i<=n; i++) {
		if(visited[i]==0 && map[x][i]) {
			dfs(i, weight+map[x][i]);
			visited[i]=0;
		}
	}
}

int main() {
	int a,b,c;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if(!map[a][b]) {
			map[a][b]=c;
			map[b][a]=c;
		} else if(map[a][b] > c) {
			map[a][b]=c;
			map[b][a]=c;
		}
	}
	visited[1]=1;
	dfs(1,0);

	(ans==987654321) ? printf("%d", -1) : printf("%d", ans);

	return 0;
}