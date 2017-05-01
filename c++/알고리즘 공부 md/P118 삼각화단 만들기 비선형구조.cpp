#include <stdio.h>

int n,ans;
int visited[101][101][101];

void dfs(int a, int b, int c) {
	visited[a][b][c]=1;
	if(a+b+c == n && a<=b && b<=c && a+b > c) {
		ans++;
		return;
	}
	if(a+b+c >= n) return;
	if(visited[a+1][b][c] == 0)
		dfs(a+1,b,c);
	if(visited[a][b+1][c] == 0)
		dfs(a,b+1,c);
	if(visited[a][b][c+1] == 0)
		dfs(a,b,c+1);
}

int main() {
	scanf("%d", &n);
	dfs(1,1,1);
	printf("%d", ans);

	return 0;
}